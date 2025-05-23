/**
 ****************************************************************************************
 *
 * @file ke.h
 *
 * @brief This file contains the definition of the kernel environment.
 *
 * Copyright (C) RivieraWaves 2009-2015
 *
 *
 ****************************************************************************************
 */

#ifndef KE_H_
#define KE_H_

#include "rom_build_cfg.h"

/**
 ****************************************************************************************
 * @addtogroup ENV Environment
 * @ingroup KERNEL
 * @brief Kernel Environment
 *
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "rwip_config.h"          // stack configuration

#include <stdbool.h>              // standard boolean definitions
#include <stdint.h>               // standard integer definitions

/*
 * ENUMERATION
 ****************************************************************************************
 */

/// Kernel Error Status
enum KE_STATUS
{
    KE_SUCCESS = 0,
    KE_FAIL
};


/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief This function performs all the initializations of the kernel.
 *
 * It initializes first the heap, then the message queues and the events. Then if required
 * it initializes the trace.
 *
 ****************************************************************************************
 */
void ke_init(void);

/**
 ****************************************************************************************
 * @brief This function flushes all messages currently pending in the kernel.
 *
 ****************************************************************************************
 */
void ke_flush(void);

/**
 ****************************************************************************************
 * @brief This function checks if sleep is possible or kernel is processing
 *
 * @return      True if sleep is allowed, false otherwise
 ****************************************************************************************
 */
bool ke_sleep_check(void);

#if (KE_PROFILING)
/**
 ****************************************************************************************
 * @brief This function gets the statistics of the kernel usage.
 *
 * @param[out]   max_msg_sent      Max message sent
 * @param[out]   max_msg_saved     Max message saved
 * @param[out]   max_timer_used    Max timer used
 * @param[out]   max_heap_used     Max heap used
 ****************************************************************************************
 */
enum KE_STATUS ke_stats_get(uint32_t* max_msg_sent, uint32_t* max_msg_saved, uint32_t* max_timer_used,
                            uint32_t* max_heap_used);
#endif //KE_PROFILING

/// @} KE

#endif // KE_H_
