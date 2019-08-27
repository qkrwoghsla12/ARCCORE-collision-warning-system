/*-------------------------------- Arctic Core ------------------------------
 * Copyright (C) 2013, ArcCore AB, Sweden, www.arccore.com.
 * Contact: <contact@arccore.com>
 * 
 * You may ONLY use this file:
 * 1)if you have a valid commercial ArcCore license and then in accordance with  
 * the terms contained in the written license agreement between you and ArcCore, 
 * or alternatively
 * 2)if you follow the terms found in GNU General Public License version 2 as 
 * published by the Free Software Foundation and appearing in the file 
 * LICENSE.GPL included in the packaging of this file or here 
 * <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>
 *-------------------------------- Arctic Core -----------------------------*/

/* Generator version: 3.0.0
 * AUTOSAR version:   4.1.2
 */


#ifndef GPT_CFG_H_
#define GPT_CFG_H_

#if !(((GPT_SW_MAJOR_VERSION == 3) && (GPT_SW_MINOR_VERSION == 0)) )
#error Gpt: Configuration file expected BSW module version to be 3.0.*
#endif

#if !(((GPT_AR_RELEASE_MAJOR_VERSION == 4) && (GPT_AR_RELEASE_MINOR_VERSION == 1)) )
#error Gpt: Configuration file expected AUTOSAR version to be 4.1.*
#endif


/** HW PIT channels */

#define GPT_CHANNEL_RTI       0   /* RTI is not configurable using GPT because it can be used by OS */
#define GPT_CHANNEL_PIT_1     1
#define GPT_CHANNEL_PIT_2     2
#define GPT_CHANNEL_PIT_3     3
#define GPT_CHANNEL_PIT_4     4
#define GPT_CHANNEL_PIT_5     5
#define GPT_CHANNEL_PIT_6     6
#define GPT_CHANNEL_PIT_7     7
#define GPT_CHANNEL_PIT_8     8
#define GPT_CHANNEL_PIT_9     9
#define GPT_CHANNEL_PIT_10    10
#define GPT_CHANNEL_PIT_11    11
#define GPT_CHANNEL_PIT_12    12
#define GPT_CHANNEL_PIT_13    13
#define GPT_CHANNEL_PIT_14    14
#define GPT_CHANNEL_PIT_15    15
#define GPT_CHANNEL_PIT_16    16
#define GPT_CHANNEL_CNT       17

/* Symbolic Channels */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration  (Gpt_ChannelType)GPT_CHANNEL_PIT_1
#define Gpt_GptChannelConfiguration  GptConf_GptChannelConfiguration_GptChannelConfiguration
#define GptConf_GptChannelConfiguration_GptChannelConfiguration2  (Gpt_ChannelType)GPT_CHANNEL_PIT_2
#define Gpt_GptChannelConfiguration2  GptConf_GptChannelConfiguration_GptChannelConfiguration2


#define GPT_CHANNEL_ILL	31


#define GPT_DEV_ERROR_DETECT				STD_ON	
#define GPT_REPORT_WAKEUP_SOURCE			STD_OFF
#define GPT_DEINIT_API  					STD_ON	
#define GPT_ENABLE_DISABLE_NOTIFICATION_API STD_ON    
#define GPT_TIME_REMAINING_API				STD_OFF	
#define GPT_TIME_ELAPSED_API                STD_ON    
#define GPT_VERSION_INFO_API				STD_OFF	
#define GPT_WAKEUP_FUNCTIONALITY_API		STD_ON

#if (GPT_REPORT_WAKEUP_SOURCE==STD_ON)
#include "EcuM_Cbk.h"
#endif

#include "Gpt_ConfigTypes.h"

/* Configuration Set Handles */
#define GptChannelConfigSet (GptConfigData)
#define Gpt_GptChannelConfigSet (GptConfigData)

extern const Gpt_ConfigType GptConfigData[];

#endif /*GPT_CFG_H_*/

