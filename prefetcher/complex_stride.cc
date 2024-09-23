#include "cache.h"

// ------------------------- DO NOT CHANGE -------------------------------- //
#define NUM_IP_TABLE_ENTRIES 1024           // IP table entries
#define PREFETCH_DEGREE 5                   // Prefetch degree
// ------------------------- DO NOT CHANGE -------------------------------- //

// ------------ YOU CAN CHANGE THE IP_TABLE FOR YOU DESIGN ---------------- //
class IP_TABLE {
  public:
    uint64_t ip_tag;
    uint64_t last_page;                     // last page seen by IP
    uint64_t last_cl_offset;                // last cl offset in the 4KB page
    int64_t last_stride;                    // last delta observed
    uint16_t ip_valid;                      // Valid IP or not   
    int conf;                               // CPLX conf
    uint16_t signature;                     // CPLX signature
    int stride;                             // Stride

    IP_TABLE () {
        ip_tag = 0;
        last_page = 0;
        last_cl_offset = 0;
        last_stride = 0;
        ip_valid = 0;
        signature = 0;
        conf = 0;
        stride = 0;
    };
};

IP_TABLE trackers_cplx[NUM_CPUS][NUM_IP_TABLE_ENTRIES];

// ------------------------- Updating the signature ---------------------------- // 
uint16_t update_sig_l1(uint16_t old_sig, int delta) {                           
    
    return new_sig;
}

// ------------------- Updating confidence for the CPLX class ------------------ // 
int update_conf(int stride, int pred_stride, int conf) {

    return conf;
}

// ------------------------- Initialize the prefetcher ------------------------- // 
void CACHE::l1d_prefetcher_initialize() 
{
	cout << "CPU " << cpu << " L1D Complex-Stride prefetcher" << endl;
    
}

// --------------- This is the main prefetcher operate function ---------------- // 
void CACHE::l1d_prefetcher_operate(uint64_t addr, uint64_t ip, uint8_t cache_hit, uint8_t type, uint8_t critical_ip_flag)
{
    uint64_t cl_addr = addr >> LOG2_BLOCK_SIZE;

	// --------------------- Add Complex-Stride pf_address logic here --------------------- // 

	prefetch_line(ip, addr, pf_address, FILL_L1, 0);

	return;

}

// ------------------------- DO NOT CHANGE -------------------------------- //
void CACHE::l1d_prefetcher_notify_about_dtlb_eviction(uint64_t addr, uint32_t set, uint32_t way, uint8_t prefetch, uint64_t evicted_addr, uint32_t metadata_in)
{

}

void CACHE::l1d_prefetcher_cache_fill(uint64_t v_addr, uint64_t addr, uint32_t set, uint32_t way, uint8_t prefetch, uint64_t v_evicted_addr, uint64_t evicted_addr, uint32_t metadata_in)
{

}

void CACHE::l1d_prefetcher_final_stats()
{
	cout << "CPU " << cpu << " L1D complex stride prefetcher final stats" << endl;
	cout << "Degree: " << PREFETCH_DEGREE << endl;
}
// ------------------------- DO NOT CHANGE -------------------------------- //