#include "cache.h"

// ------------------------- DO NOT CHANGE -------------------------------- //
#define IP_TRACKER_COUNT 64           // Number of IP trackers
// ------------------------- DO NOT CHANGE -------------------------------- //

#define PREFETCH_DEGREE 5             // Prefetch degree - you need to vary this!

class IP_TRACKER {
  public:
    // ------------------------- Define the IP_TRACKER class here ------------------------- //

};

IP_TRACKER trackers[IP_TRACKER_COUNT];

// ------------------------- Initialize the prefetcher ------------------------- // 
void CACHE::stlb_prefetcher_initialize() 
{
	cout << "CPU " << cpu << " STLB arbitrary stride prefetcher" << endl;

}

// --------------- This is the main prefetcher operate function ---------------- // 
void CACHE::stlb_prefetcher_operate(uint64_t addr, uint64_t ip, uint8_t cache_hit, uint8_t type, uint64_t prefetch_id, uint8_t instruction)
{
    // ------------------------ Add Arbitrary Stride pf_address logic here ----------------------- // 

    prefetch_translation(ip, pf_address, (int)2, 0, prefetch_id, instruction);
    
    return;
}

// ------------------------- DO NOT CHANGE -------------------------------- //
void CACHE::stlb_prefetcher_cache_fill(uint64_t addr, uint32_t set, uint32_t way, uint8_t prefetch, uint64_t evicted_addr, uint32_t metadata_in)
{
    return;
}

void CACHE::stlb_prefetcher_final_stats()
{
    cout << "CPU " << cpu << " STLB arbitrary stride prefetcher final stats" << endl;
	cout << "Degree: " << PREFETCH_DEGREE << endl;
}
// ------------------------- DO NOT CHANGE -------------------------------- //