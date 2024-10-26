#include "sbfp.h"

SBFP::SBFP() {
    fdt_counters.fill(0);
}

int SBFP::free_distance_to_index(int free_distance) {
    if (free_distance < -7 || free_distance > 7 || free_distance == 0) {
        return -1; // Invalid free distance
    }
    return (free_distance < 0) ? (free_distance + 7) : (free_distance + 6);
}

void SBFP::process_page_walk(uint64_t demand_virtual_page, uint64_t demand_physical_page) {
    // Identify the position of the requested PTE within the cache line (positions 0-7)
    int demand_pte_position = demand_virtual_page & 0x7;

    // Iterate over all possible free distances
    for (int fd = -7; fd <= 7; ++fd) {
        if (fd == 0) continue; // Exclude 0
        int index = free_distance_to_index(fd);
        if (index == -1) continue; // Skip invalid free distances

        uint64_t free_virtual_page = demand_virtual_page + fd;

        SBFPEntry entry;
        entry.virtual_page = free_virtual_page;
        entry.physical_page = 0; // Physical page to be resolved
        entry.free_distance = fd;

        if (fdt_counters[index] > FDT_THRESHOLD) {
            insert_into_pq(entry);
        } else {
            insert_into_sampler(entry);
        }
    }
}

bool SBFP::pq_lookup(uint64_t virtual_page, uint64_t& physical_page) {
    for (auto it = pq_entries.begin(); it != pq_entries.end(); ++it) {
        if (it->virtual_page == virtual_page) {
            physical_page = it->physical_page; // Physical page should be resolved
            update_fdt_on_hit(it->free_distance);
            return true;
        }
    }
    return false;
}

bool SBFP::sampler_lookup(uint64_t virtual_page) {
    for (auto it = sampler_entries.begin(); it != sampler_entries.end(); ++it) {
        if (it->virtual_page == virtual_page) {
            update_fdt_on_hit(it->free_distance);
            return true;
        }
    }
    return false;
}

void SBFP::update_fdt_on_hit(int free_distance) {
    int index = free_distance_to_index(free_distance);
    if (index == -1) return;

    if (fdt_counters[index] < FDT_MAX_VALUE) {
        fdt_counters[index]++;
        if (fdt_counters[index] == FDT_MAX_VALUE) {
            decay_counters();
        }
    }
}

void SBFP::decay_counters() {
    for (auto& counter : fdt_counters) {
        counter >>= 1;
    }
}

void SBFP::insert_into_pq(const SBFPEntry& entry) {
    if (pq_entries.size() >= PQ_SIZE) {
        pq_entries.pop_back(); // Evict the oldest entry (FIFO)
    }
    pq_entries.push_front(entry);
}

void SBFP::insert_into_sampler(const SBFPEntry& entry) {
    if (sampler_entries.size() >= SAMPLER_SIZE) {
        sampler_entries.pop_back(); // Evict the oldest entry (FIFO)
    }
    sampler_entries.push_front(entry);
}
