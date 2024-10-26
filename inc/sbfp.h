#ifndef SBFP_H
#define SBFP_H

#include <array>
#include <list>
#include <cstdint>

class SBFPEntry {
public:
    uint64_t virtual_page;
    uint64_t physical_page;
    int free_distance;
};

class SBFP {
public:
    SBFP();
    void process_page_walk(uint64_t demand_virtual_page, uint64_t demand_physical_page);
    bool pq_lookup(uint64_t virtual_page, uint64_t& physical_page);
    bool sampler_lookup(uint64_t virtual_page);
    void update_fdt_on_hit(int free_distance);
    void decay_counters();

private:
    static const int NUM_FREE_DISTANCES = 14; // -7 to +7 excluding 0
    static const int FDT_THRESHOLD = 100;
    static const int FDT_MAX_VALUE = 1023; // 10-bit counter max value
    static const int PQ_SIZE = 64;
    static const int SAMPLER_SIZE = 64;

    std::array<uint16_t, NUM_FREE_DISTANCES> fdt_counters; // 10-bit saturating counters
    std::list<SBFPEntry> pq_entries;     // Prefetch Queue (PQ)
    std::list<SBFPEntry> sampler_entries; // Sampler

    int free_distance_to_index(int free_distance);
    void insert_into_pq(const SBFPEntry& entry);
    void insert_into_sampler(const SBFPEntry& entry);
};

#endif // SBFP_H
