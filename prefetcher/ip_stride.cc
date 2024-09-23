#include "cache.h"

// ------------------------- DO NOT CHANGE -------------------------------- //
#define IP_TRACKER_COUNT 64           // Number of IP trackers
#define PREFETCH_DEGREE 5             // Prefetch degree
// ------------------------- DO NOT CHANGE -------------------------------- //

class IP_TRACKER {
  public:
    // ------------------------- Define the IP_TRACKER class here ------------------------- //
    
};

IP_TRACKER trackers[IP_TRACKER_COUNT];

// ------------------------- Initialize the prefetcher ------------------------- // 
void CACHE::l1d_prefetcher_initialize() 
{
	cout << "CPU " << cpu << " L1D IP-based stride prefetcher" << endl;

}

// --------------- This is the main prefetcher operate function ---------------- // 
void CACHE::l1d_prefetcher_operate(uint64_t addr, uint64_t ip, uint8_t cache_hit, uint8_t type, uint8_t critical_ip_flag, double coverage)
{
    uint64_t cl_addr = addr >> LOG2_BLOCK_SIZE;

    // ------------------------ Add IP-Stride pf_address logic here ----------------------- // 

    prefetch_line(ip, addr, pf_address, FILL_L1, 0);

    return;
}

// ------------------------- DO NOT CHANGE -------------------------------- //
void CACHE::l1d_prefetcher_cache_fill(uint64_t v_addr, uint64_t addr, uint32_t set, uint32_t way, uint8_t prefetch, uint64_t v_evicted_addr, uint64_t evicted_addr, uint32_t metadata_in)
{
	return;
}

void CACHE::l1d_prefetcher_final_stats()
{
	cout << "CPU " << cpu << " L1D IP-based stride prefetcher final stats" << endl;
	cout << "Degree: " << PREFETCH_DEGREE << endl;
}
// ------------------------- DO NOT CHANGE -------------------------------- //