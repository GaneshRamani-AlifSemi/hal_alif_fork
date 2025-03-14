/**
 ****************************************************************************************
 *
 * @file uds_common.h
 *
 * @brief Header File - User Data Service Profile common types.
 *
 * Copyright (C) RivieraWaves 2009-2025
 * Release Identifier: 0e0cd311
 *
 *
 ****************************************************************************************
 */


#ifndef _UDS_COMMON_H_
#define _UDS_COMMON_H_

#include "rom_build_cfg.h"

#include "prf_types.h"
#include <stdint.h> 
#include "gatt.h"

/*
 * DEFINES
 ****************************************************************************************
 */

/// user control point maximum size
#define UDS_USER_CTRL_PT_MAX_LEN        (19)
/// CCC maximum size
#define UDS_CCC_SIZE                    sizeof(uint16_t)
/// Maximum extended size
#define UDS_EXT_SIZE                    sizeof(uint16_t)
/// string maximum size
#define UDS_STRING_MAX_SIZE             (255)
/// date maximum size
#define UDS_DATE_MAX_SIZE               (sizeof(prf_date_t))
/// uint8 maximum size
#define UDS_UINT8_MAX_SIZE              (sizeof(uint8_t))
/// uint16 maximum size
#define UDS_UINT16_MAX_SIZE             (sizeof(uint16_t))
/// Unknown user
#define UDS_USER_ID_UNKNOWN_USER        (0xFF)
///  CT Point timeout (in milliseconds)
#define UDS_CP_TIMEOUT                  (30000)

/// Buffer Header length that must be reserved for processing
#define UDS_BUFFER_HEADER_LEN          (GATT_BUFFER_HEADER_LEN)
/// Buffer Tail length that must be reserved for processing
#define UDS_BUFFER_TAIL_LEN            (GATT_BUFFER_TAIL_LEN)

/// Characteristic Index
enum uds_val_id
{
    /// Strings: utf8s
    UDS_CHAR_ID_FIRST_NAME                                      = 0,
    UDS_CHAR_ID_LAST_NAME                                       = 1,
    UDS_CHAR_ID_EMAIL_ADDRESS                                   = 2,
    UDS_CHAR_ID_LANGUAGE                                        = 3,
    /// Date
    UDS_CHAR_ID_DATE_OF_BIRTH                                   = 4,
    UDS_CHAR_ID_DATE_OF_THR_ASSESS                              = 5,
    /// uint16
    UDS_CHAR_ID_WEIGHT                                          = 6,
    UDS_CHAR_ID_HEIGHT                                          = 7,
    UDS_CHAR_ID_WAIST_CIRCUMFERENCE                             = 8,
    UDS_CHAR_ID_HIP_CIRCUMFERENCE                               = 9,
    /// uint8
    UDS_CHAR_ID_AGE                                             = 10,
    UDS_CHAR_ID_GENDER                                          = 11,
    UDS_CHAR_ID_VO2_MAX                                         = 12,
    UDS_CHAR_ID_MAX_HEART_RATE                                  = 13,
    UDS_CHAR_ID_RESTING_HEART_RATE                              = 14,
    UDS_CHAR_ID_MAX_RECO_HEART_RATE                             = 15,
    UDS_CHAR_ID_AEROBIC_THR                                     = 16,
    UDS_CHAR_ID_ANAERO_THR                                      = 17,
    UDS_CHAR_ID_SPORT_TYPE_FOR_AERO_ANAREO_THRS                 = 18,
    UDS_CHAR_ID_FAT_BURN_HEART_RATE_LOW_LIM                     = 19,
    UDS_CHAR_ID_FAT_BURN_HEART_RATE_UP_LIM                      = 20,
    UDS_CHAR_ID_AEROBIC_HEART_RATE_LOW_LIM                      = 21,
    UDS_CHAR_ID_AEROBIC_HEART_RATE_UP_LIM                       = 22,
    UDS_CHAR_ID_ANAERO_HEART_RATE_LOW_LIM                       = 23,
    UDS_CHAR_ID_ANAERO_HEART_RATE_UP_LIM                        = 24,
    UDS_CHAR_ID_TWO_ZONE_HEART_RATE_LIMITS                      = 25,
    /// set
    UDS_CHAR_ID_FIVE_ZONE_HEART_RATE_LIMITS                     = 26,
    UDS_CHAR_ID_THREE_ZONE_HEART_RATE_LIMITS                    = 27,
    UDS_CHAR_ID_USER_DEFINED_1                                  = 28,
    UDS_CHAR_ID_USER_DEFINED_2                                  = 29,
    UDS_CHAR_ID_USER_DEFINED_3                                  = 30,
    UDS_CHAR_ID_USER_DEFINED_4                                  = 31,
    /// control
    UDS_CHAR_ID_DB_CHG_INC                                      = 32,
    UDS_CHAR_ID_USER_INDEX                                      = 33,
    UDS_CHAR_ID_USER_CTRL_PT                                    = 34,
    /// UNKNOWN
    UDS_CHAR_ID_UNKNOWN                                         = 255,
};

/// User Control Point Op-codes
enum uds_ctrl_pt_op_code
{
    UDS_OP_CODE_RESERVED_00             = 0x00,
    UDS_OP_CODE_REGISTER_NEW_USER       = 0x01,
    UDS_OP_CODE_CONSENT                 = 0x02,
    UDS_OP_CODE_DELETE_USER_DATA        = 0x03,
    UDS_OP_CODE_RESPONSE_CODE           = 0x20,
};

/// User Control Point Response
enum uds_ctrl_pt_response
{
    UDS_OP_RESPONSE_RESERVED_00             = 0x00,
    UDS_OP_RESPONSE_SUCCESS                 = 0x01,
    UDS_OP_RESPONSE_OP_CODE_NOT_SUPPORTED   = 0x02,
    UDS_OP_RESPONSE_INVALID_PARAMETER       = 0x03,
    UDS_OP_RESPONSE_OPERATION_FAILED        = 0x04,
    UDS_OP_RESPONSE_USER_NOT_AUTHORIZED     = 0x05,
};

/// UDS Gender characteristic - Gender of the user
enum uds_gender_value
{
    UDS_GENDER_MALE             = 0,
    UDS_GENDER_FEMALE           = 1,
    UDS_GENDER_UNSPECIFIED      = 2,
    // 3 - 255 RFU
};

/// UDS Sport Type for Aerobic and Anaerobic Thresholds characteristic
enum uds_sport_type_for_aerobic_and_anAEROBIC_THRs_value
{
    UDS_SPORT_TYPE_FOR_AERO_ANAREO_THRS_UNSPECIFIED                 = 0,
    UDS_SPORT_TYPE_FOR_AERO_ANAREO_THRS_RUNNING                     = 1,
    UDS_SPORT_TYPE_FOR_AERO_ANAREO_THRS_CYCLING                     = 2,
    UDS_SPORT_TYPE_FOR_AERO_ANAREO_THRS_ROWING                      = 3,
    UDS_SPORT_TYPE_FOR_AERO_ANAREO_THRS_CROSS_TRAINING              = 4,
    UDS_SPORT_TYPE_FOR_AERO_ANAREO_THRS_CLIMBING                    = 5,
    UDS_SPORT_TYPE_FOR_AERO_ANAREO_THRS_SKIING                      = 6,
    UDS_SPORT_TYPE_FOR_AERO_ANAREO_THRS_SKATING                     = 7,
    UDS_SPORT_TYPE_FOR_AERO_ANAREO_THRS_ARM_EXERCISING              = 8,
    UDS_SPORT_TYPE_FOR_AERO_ANAREO_THRS_LOWER_BODY_EXERCISING       = 9,
    UDS_SPORT_TYPE_FOR_AERO_ANAREO_THRS_UPPER_BODY_EXERCISING       = 10,
    UDS_SPORT_TYPE_FOR_AERO_ANAREO_THRS_WHOLE_BODY_EXERCISING       = 11,
    // 13 - 255 RFU
};

/*
 * STRUCTURES
 ****************************************************************************************
 */


/// Characteristic value
union uds_value
{
    /// Date value
    prf_date_t      date;
    /// Database Change Increment value
    uint32_t        db_chg_inc;
    /// User Index value
    uint8_t         user_idx;
    /// All 8 bits values depending on char_idx see enum #udsc_char_idx:
    /// Age value
    /// Gender of the user see enum #uds_gender_type
    /// VO2 Max Unit is in Milliliter per kilogram per minutes with a resolution of 1
    /// Maximum heart rate a user can reach
    /// Lowest Heart Rate a user can reach
    /// Maximum recommended heart rate is a threshold that may be set to limit exertion.
    /// First metabolic threshold. The Unit is beats per minute with a resolution of 1
    /// Second metabolic threshold. The Unit is beats per minute with a resolution of 1
    /// Sport type enumeration see enum #uds_sport_type_for_aerobic_and_anAEROBIC_THRs_value
    /// Lower limit of the heart rate where the user maximizes the fat burn while exercising
    /// Upper limit of the heart rate where the user maximizes the fat burn while exercising
    /// Lower limit of the heart rate where the user enhances his endurance while exercising
    /// Upper limit of the heart rate where the user enhances his endurance while exercising
    /// Lower limit of the heart rate where the user enhances his anaerobic tolerance while exercising
    /// Upper limit of the heart rate where the user enhances his anaerobic tolerance while exercising
    /// Heart rate limit between the heart rate zones for the 2-zone heart rate definition (Fitness and Fat Burn)
    uint8_t         uint8;

    /// 16 bits value - Weight
    uint16_t        uint16;

    /// Heart Rate Limits
    uint8_t         set[4];
};

#endif // _UDS_COMMON_H_

