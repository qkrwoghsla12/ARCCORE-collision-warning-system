
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

/* Generator version: 1.1.0
 * AUTOSAR version:   4.0.3
 */
/*lint -emacro(904,IOHWAB_VALIDATE_RETURN)*/ /*904 PC-Lint exception to MISRA 14.7 (validate DET macros)*/

#include "IoHwAb.h"
#include "IoHwAb_Internal.h"
#include "IoHwAb_Digital.h"
#include "IoHwAb_Dcm.h"
#include "SchM_IoHwAb.h"
#if defined(USE_DIO)
#include "Dio.h"
#else
#error "DIO Module is needed by IOHWAB"
#endif


#if defined(USE_DET) 
#include "Det.h"
#else
#error Need to add DET module when ArcIoHwAbDevErrorDetect is enabled
#endif 


#define IS_VALID_DIO_LEVEL(_x) ((STD_LOW == (_x)) || (STD_HIGH == (_x)))


/* Signals states for I/O-control */
/* Digital signal: DigitalFrontLED */

#define IOHWAB_START_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_BswMemMap.h"
boolean IoHwAb_DigitalFrontLED_Locked = FALSE;
#define IOHWAB_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_BswMemMap.h"  /*lint !e9019 OTHER [MISRA 2012 Rule 20.1, advisory] OTHER AUTOSAR specified way of using MemMap*/

#define IOHWAB_START_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_BswMemMap.h"
IoHwAb_LevelType IoHwAb_DigitalFrontLED_Saved = IOHWAB_LOW;
#define IOHWAB_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_BswMemMap.h"  /*lint !e9019 OTHER [MISRA 2012 Rule 20.1, advisory] OTHER AUTOSAR specified way of using MemMap*/

const IoHwAb_LevelType IoHwAb_DigitalFrontLED_Default = IOHWAB_LOW;

/* Digital signal: DigitalRearLED */

#define IOHWAB_START_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_BswMemMap.h"
boolean IoHwAb_DigitalRearLED_Locked = FALSE;
#define IOHWAB_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_BswMemMap.h"  /*lint !e9019 OTHER [MISRA 2012 Rule 20.1, advisory] OTHER AUTOSAR specified way of using MemMap*/

#define IOHWAB_START_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_BswMemMap.h"
IoHwAb_LevelType IoHwAb_DigitalRearLED_Saved = IOHWAB_LOW;
#define IOHWAB_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_BswMemMap.h"  /*lint !e9019 OTHER [MISRA 2012 Rule 20.1, advisory] OTHER AUTOSAR specified way of using MemMap*/

const IoHwAb_LevelType IoHwAb_DigitalRearLED_Default = IOHWAB_LOW;

/* Digital signal: DigitalSonarEcho */

#define IOHWAB_START_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_BswMemMap.h"
boolean IoHwAb_DigitalSonarEcho_Locked = FALSE;
#define IOHWAB_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_BswMemMap.h"  /*lint !e9019 OTHER [MISRA 2012 Rule 20.1, advisory] OTHER AUTOSAR specified way of using MemMap*/

#define IOHWAB_START_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_BswMemMap.h"
IoHwAb_LevelType IoHwAb_DigitalSonarEcho_Saved = IOHWAB_LOW;
#define IOHWAB_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_BswMemMap.h"  /*lint !e9019 OTHER [MISRA 2012 Rule 20.1, advisory] OTHER AUTOSAR specified way of using MemMap*/

const IoHwAb_LevelType IoHwAb_DigitalSonarEcho_Default = IOHWAB_LOW;

/* Digital signal: DigitalSonarTrig */

#define IOHWAB_START_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_BswMemMap.h"
boolean IoHwAb_DigitalSonarTrig_Locked = FALSE;
#define IOHWAB_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_BswMemMap.h"  /*lint !e9019 OTHER [MISRA 2012 Rule 20.1, advisory] OTHER AUTOSAR specified way of using MemMap*/

#define IOHWAB_START_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_BswMemMap.h"
IoHwAb_LevelType IoHwAb_DigitalSonarTrig_Saved = IOHWAB_LOW;
#define IOHWAB_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_BswMemMap.h"  /*lint !e9019 OTHER [MISRA 2012 Rule 20.1, advisory] OTHER AUTOSAR specified way of using MemMap*/

const IoHwAb_LevelType IoHwAb_DigitalSonarTrig_Default = IOHWAB_LOW;

Std_ReturnType IoHwAb_Digital_Write_DigitalFrontLED(IoHwAb_LevelType newValue)
{
	IOHWAB_VALIDATE_RETURN(IS_VALID_DIO_LEVEL((Dio_LevelType)newValue), IOHWAB_DIGITAL_WRITE_ID, IOHWAB_E_PARAM_LEVEL, E_NOT_OK);
	Dio_LevelType setLevel;
	if( TRUE == IoHwAb_DigitalFrontLED_Locked ) {
		setLevel = IoHwAb_DigitalFrontLED_Saved;
	} else {
		setLevel = newValue;
	}
	IoHwAb_DigitalFrontLED_Saved = setLevel;
	/* @req ARCIOHWAB004 */
	Dio_WriteChannel(DioConf_DioChannel_FrontLED, setLevel);
	return E_OK;
}

Std_ReturnType IoHwAb_Digital_Write_DigitalRearLED(IoHwAb_LevelType newValue)
{
	IOHWAB_VALIDATE_RETURN(IS_VALID_DIO_LEVEL((Dio_LevelType)newValue), IOHWAB_DIGITAL_WRITE_ID, IOHWAB_E_PARAM_LEVEL, E_NOT_OK);
	Dio_LevelType setLevel;
	if( TRUE == IoHwAb_DigitalRearLED_Locked ) {
		setLevel = IoHwAb_DigitalRearLED_Saved;
	} else {
		setLevel = newValue;
	}
	IoHwAb_DigitalRearLED_Saved = setLevel;
	/* @req ARCIOHWAB004 */
	Dio_WriteChannel(DioConf_DioChannel_RearLED, setLevel);
	return E_OK;
}

Std_ReturnType IoHwAb_Digital_Write_DigitalSonarTrig(IoHwAb_LevelType newValue)
{
	IOHWAB_VALIDATE_RETURN(IS_VALID_DIO_LEVEL((Dio_LevelType)newValue), IOHWAB_DIGITAL_WRITE_ID, IOHWAB_E_PARAM_LEVEL, E_NOT_OK);
	Dio_LevelType setLevel;
	if( TRUE == IoHwAb_DigitalSonarTrig_Locked ) {
		setLevel = IoHwAb_DigitalSonarTrig_Saved;
	} else {
		setLevel = newValue;
	}
	IoHwAb_DigitalSonarTrig_Saved = setLevel;
	/* @req ARCIOHWAB004 */
	Dio_WriteChannel(DioConf_DioChannel_SonarTrig, setLevel);
	return E_OK;
}

/* @req ARCIOHWAB011 */
Std_ReturnType IoHwAb_Digital_Read_DigitalFrontLED(IoHwAb_LevelType *value, IoHwAb_StatusType *status)
{
	IOHWAB_VALIDATE_RETURN((NULL != value), IOHWAB_DIGITAL_READ_ID, IOHWAB_E_PARAM_PTR, E_NOT_OK);
	IOHWAB_VALIDATE_RETURN((NULL != status), IOHWAB_DIGITAL_READ_ID, IOHWAB_E_PARAM_PTR, E_NOT_OK);
	*value = Dio_ReadChannel(DioConf_DioChannel_FrontLED);
	status->quality = IOHWAB_GOOD;

	return E_OK;
}

/* @req ARCIOHWAB011 */
Std_ReturnType IoHwAb_Digital_Read_DigitalRearLED(IoHwAb_LevelType *value, IoHwAb_StatusType *status)
{
	IOHWAB_VALIDATE_RETURN((NULL != value), IOHWAB_DIGITAL_READ_ID, IOHWAB_E_PARAM_PTR, E_NOT_OK);
	IOHWAB_VALIDATE_RETURN((NULL != status), IOHWAB_DIGITAL_READ_ID, IOHWAB_E_PARAM_PTR, E_NOT_OK);
	*value = Dio_ReadChannel(DioConf_DioChannel_RearLED);
	status->quality = IOHWAB_GOOD;

	return E_OK;
}

/* @req ARCIOHWAB011 */
Std_ReturnType IoHwAb_Digital_Read_DigitalSonarEcho(IoHwAb_LevelType *value, IoHwAb_StatusType *status)
{
	IOHWAB_VALIDATE_RETURN((NULL != value), IOHWAB_DIGITAL_READ_ID, IOHWAB_E_PARAM_PTR, E_NOT_OK);
	IOHWAB_VALIDATE_RETURN((NULL != status), IOHWAB_DIGITAL_READ_ID, IOHWAB_E_PARAM_PTR, E_NOT_OK);
	if( FALSE == IoHwAb_DigitalSonarEcho_Locked ) {
		*value = Dio_ReadChannel(DioConf_DioChannel_SonarEcho);
	} else {
		*value = IoHwAb_DigitalSonarEcho_Saved;
	}
	status->quality = IOHWAB_GOOD;

	return E_OK;
}

/* @req ARCIOHWAB011 */
Std_ReturnType IoHwAb_Digital_Read_DigitalSonarTrig(IoHwAb_LevelType *value, IoHwAb_StatusType *status)
{
	IOHWAB_VALIDATE_RETURN((NULL != value), IOHWAB_DIGITAL_READ_ID, IOHWAB_E_PARAM_PTR, E_NOT_OK);
	IOHWAB_VALIDATE_RETURN((NULL != status), IOHWAB_DIGITAL_READ_ID, IOHWAB_E_PARAM_PTR, E_NOT_OK);
	*value = Dio_ReadChannel(DioConf_DioChannel_SonarTrig);
	status->quality = IOHWAB_GOOD;

	return E_OK;
}

/* Exported functions */
/* Digital signal: DigitalFrontLED */
/* @req ARCIOHWAB003 */
Std_ReturnType IoHwAb_Dcm_DigitalFrontLED(uint8 action, uint8* value)
{
	Std_ReturnType ret = E_OK;
	SchM_Enter_IoHwAb_EA_0();
	boolean tempLock = IoHwAb_DigitalFrontLED_Locked;
	switch(action) {
	case IOHWAB_RETURNCONTROLTOECU:
		IoHwAb_DigitalFrontLED_Locked = FALSE;
		break;
	case IOHWAB_RESETTODEFAULT:
		IoHwAb_DigitalFrontLED_Locked = FALSE;
		if(E_OK != IoHwAb_Digital_Write_DigitalFrontLED(IoHwAb_DigitalFrontLED_Default)) {
			IoHwAb_DigitalFrontLED_Locked = tempLock;
			ret = E_NOT_OK;
		} else {
			IoHwAb_DigitalFrontLED_Saved = IoHwAb_DigitalFrontLED_Default;
			IoHwAb_DigitalFrontLED_Locked = TRUE;
		}
		break;
	case IOHWAB_FREEZECURRENTSTATE:
		IoHwAb_DigitalFrontLED_Locked = TRUE;
		break;
	case IOHWAB_SHORTTERMADJUST:
		{
			IoHwAb_LevelType level = *value; 
			if(IS_VALID_DIO_LEVEL((Dio_LevelType)level)) {
				IoHwAb_DigitalFrontLED_Locked = FALSE;
				if(E_OK != IoHwAb_Digital_Write_DigitalFrontLED(level)) {
					IoHwAb_DigitalFrontLED_Locked = tempLock;
					ret = E_NOT_OK;
				} else {
					IoHwAb_DigitalFrontLED_Saved = level;
					IoHwAb_DigitalFrontLED_Locked = TRUE;
				}
			} else {
				IOHWAB_DET_REPORT_ERROR(IOHWAB_DIGITAL_IO_CONTROL_ID, IOHWAB_E_PARAM_LEVEL);
				ret = E_NOT_OK;
			}
		}
		break;
	default:
		IOHWAB_DET_REPORT_ERROR(IOHWAB_DIGITAL_IO_CONTROL_ID, IOHWAB_E_PARAM_ACTION);
		ret = E_NOT_OK;
		break;
	}
	SchM_Exit_IoHwAb_EA_0();
	return ret;
}


Std_ReturnType IoHwAb_Dcm_Read_DigitalFrontLED(uint8* value)
{
	Std_ReturnType ret;
	IoHwAb_StatusType status;
	IoHwAb_LevelType level;
	SchM_Enter_IoHwAb_EA_0();
	boolean tempLock = IoHwAb_DigitalFrontLED_Locked;
	IoHwAb_DigitalFrontLED_Locked = FALSE;
	ret = IoHwAb_Digital_Read_DigitalFrontLED(&level, &status);
	*value = level; 
	IoHwAb_DigitalFrontLED_Locked = tempLock;
	SchM_Exit_IoHwAb_EA_0();
	return ret;
}

	


/* Digital signal: DigitalRearLED */
/* @req ARCIOHWAB003 */
Std_ReturnType IoHwAb_Dcm_DigitalRearLED(uint8 action, uint8* value)
{
	Std_ReturnType ret = E_OK;
	SchM_Enter_IoHwAb_EA_0();
	boolean tempLock = IoHwAb_DigitalRearLED_Locked;
	switch(action) {
	case IOHWAB_RETURNCONTROLTOECU:
		IoHwAb_DigitalRearLED_Locked = FALSE;
		break;
	case IOHWAB_RESETTODEFAULT:
		IoHwAb_DigitalRearLED_Locked = FALSE;
		if(E_OK != IoHwAb_Digital_Write_DigitalRearLED(IoHwAb_DigitalRearLED_Default)) {
			IoHwAb_DigitalRearLED_Locked = tempLock;
			ret = E_NOT_OK;
		} else {
			IoHwAb_DigitalRearLED_Saved = IoHwAb_DigitalRearLED_Default;
			IoHwAb_DigitalRearLED_Locked = TRUE;
		}
		break;
	case IOHWAB_FREEZECURRENTSTATE:
		IoHwAb_DigitalRearLED_Locked = TRUE;
		break;
	case IOHWAB_SHORTTERMADJUST:
		{
			IoHwAb_LevelType level = *value; 
			if(IS_VALID_DIO_LEVEL((Dio_LevelType)level)) {
				IoHwAb_DigitalRearLED_Locked = FALSE;
				if(E_OK != IoHwAb_Digital_Write_DigitalRearLED(level)) {
					IoHwAb_DigitalRearLED_Locked = tempLock;
					ret = E_NOT_OK;
				} else {
					IoHwAb_DigitalRearLED_Saved = level;
					IoHwAb_DigitalRearLED_Locked = TRUE;
				}
			} else {
				IOHWAB_DET_REPORT_ERROR(IOHWAB_DIGITAL_IO_CONTROL_ID, IOHWAB_E_PARAM_LEVEL);
				ret = E_NOT_OK;
			}
		}
		break;
	default:
		IOHWAB_DET_REPORT_ERROR(IOHWAB_DIGITAL_IO_CONTROL_ID, IOHWAB_E_PARAM_ACTION);
		ret = E_NOT_OK;
		break;
	}
	SchM_Exit_IoHwAb_EA_0();
	return ret;
}


Std_ReturnType IoHwAb_Dcm_Read_DigitalRearLED(uint8* value)
{
	Std_ReturnType ret;
	IoHwAb_StatusType status;
	IoHwAb_LevelType level;
	SchM_Enter_IoHwAb_EA_0();
	boolean tempLock = IoHwAb_DigitalRearLED_Locked;
	IoHwAb_DigitalRearLED_Locked = FALSE;
	ret = IoHwAb_Digital_Read_DigitalRearLED(&level, &status);
	*value = level; 
	IoHwAb_DigitalRearLED_Locked = tempLock;
	SchM_Exit_IoHwAb_EA_0();
	return ret;
}

	


/* Digital signal: DigitalSonarEcho */
/* @req ARCIOHWAB003 */
Std_ReturnType IoHwAb_Dcm_DigitalSonarEcho(uint8 action, uint8* value)
{
	Std_ReturnType ret = E_OK;
	IoHwAb_StatusType status;
	SchM_Enter_IoHwAb_EA_0();
	boolean tempLock = IoHwAb_DigitalSonarEcho_Locked;
	switch(action) {
	case IOHWAB_RETURNCONTROLTOECU:
		IoHwAb_DigitalSonarEcho_Locked = FALSE;
		break;
	case IOHWAB_RESETTODEFAULT:
		IoHwAb_DigitalSonarEcho_Saved = IoHwAb_DigitalSonarEcho_Default;
		IoHwAb_DigitalSonarEcho_Locked = TRUE;
		break;
	case IOHWAB_FREEZECURRENTSTATE:
		IoHwAb_DigitalSonarEcho_Locked = FALSE;
		if(E_OK != IoHwAb_Digital_Read_DigitalSonarEcho(&IoHwAb_DigitalSonarEcho_Saved, &status)) {
			IoHwAb_DigitalSonarEcho_Locked = tempLock;
			ret = E_NOT_OK;
		} else {
			IoHwAb_DigitalSonarEcho_Locked = TRUE;
		}
		break;
	case IOHWAB_SHORTTERMADJUST:
		{
			IoHwAb_LevelType level = *value; 
			if(IS_VALID_DIO_LEVEL((Dio_LevelType)level)) {
				IoHwAb_DigitalSonarEcho_Saved = level;
				IoHwAb_DigitalSonarEcho_Locked = TRUE;
			} else {
				IOHWAB_DET_REPORT_ERROR(IOHWAB_DIGITAL_IO_CONTROL_ID, IOHWAB_E_PARAM_LEVEL);
				ret = E_NOT_OK;
			}
		}
		break;
	default:
		IOHWAB_DET_REPORT_ERROR(IOHWAB_DIGITAL_IO_CONTROL_ID, IOHWAB_E_PARAM_ACTION);
		ret = E_NOT_OK;
		break;
	}
	SchM_Exit_IoHwAb_EA_0();
	return ret;
}


Std_ReturnType IoHwAb_Dcm_Read_DigitalSonarEcho(uint8* value)
{
	Std_ReturnType ret;
	IoHwAb_StatusType status;
	IoHwAb_LevelType level;
	SchM_Enter_IoHwAb_EA_0();
	boolean tempLock = IoHwAb_DigitalSonarEcho_Locked;
	IoHwAb_DigitalSonarEcho_Locked = FALSE;
	ret = IoHwAb_Digital_Read_DigitalSonarEcho(&level, &status);
	*value = level; 
	IoHwAb_DigitalSonarEcho_Locked = tempLock;
	SchM_Exit_IoHwAb_EA_0();
	return ret;
}

	


/* Digital signal: DigitalSonarTrig */
/* @req ARCIOHWAB003 */
Std_ReturnType IoHwAb_Dcm_DigitalSonarTrig(uint8 action, uint8* value)
{
	Std_ReturnType ret = E_OK;
	SchM_Enter_IoHwAb_EA_0();
	boolean tempLock = IoHwAb_DigitalSonarTrig_Locked;
	switch(action) {
	case IOHWAB_RETURNCONTROLTOECU:
		IoHwAb_DigitalSonarTrig_Locked = FALSE;
		break;
	case IOHWAB_RESETTODEFAULT:
		IoHwAb_DigitalSonarTrig_Locked = FALSE;
		if(E_OK != IoHwAb_Digital_Write_DigitalSonarTrig(IoHwAb_DigitalSonarTrig_Default)) {
			IoHwAb_DigitalSonarTrig_Locked = tempLock;
			ret = E_NOT_OK;
		} else {
			IoHwAb_DigitalSonarTrig_Saved = IoHwAb_DigitalSonarTrig_Default;
			IoHwAb_DigitalSonarTrig_Locked = TRUE;
		}
		break;
	case IOHWAB_FREEZECURRENTSTATE:
		IoHwAb_DigitalSonarTrig_Locked = TRUE;
		break;
	case IOHWAB_SHORTTERMADJUST:
		{
			IoHwAb_LevelType level = *value; 
			if(IS_VALID_DIO_LEVEL((Dio_LevelType)level)) {
				IoHwAb_DigitalSonarTrig_Locked = FALSE;
				if(E_OK != IoHwAb_Digital_Write_DigitalSonarTrig(level)) {
					IoHwAb_DigitalSonarTrig_Locked = tempLock;
					ret = E_NOT_OK;
				} else {
					IoHwAb_DigitalSonarTrig_Saved = level;
					IoHwAb_DigitalSonarTrig_Locked = TRUE;
				}
			} else {
				IOHWAB_DET_REPORT_ERROR(IOHWAB_DIGITAL_IO_CONTROL_ID, IOHWAB_E_PARAM_LEVEL);
				ret = E_NOT_OK;
			}
		}
		break;
	default:
		IOHWAB_DET_REPORT_ERROR(IOHWAB_DIGITAL_IO_CONTROL_ID, IOHWAB_E_PARAM_ACTION);
		ret = E_NOT_OK;
		break;
	}
	SchM_Exit_IoHwAb_EA_0();
	return ret;
}


Std_ReturnType IoHwAb_Dcm_Read_DigitalSonarTrig(uint8* value)
{
	Std_ReturnType ret;
	IoHwAb_StatusType status;
	IoHwAb_LevelType level;
	SchM_Enter_IoHwAb_EA_0();
	boolean tempLock = IoHwAb_DigitalSonarTrig_Locked;
	IoHwAb_DigitalSonarTrig_Locked = FALSE;
	ret = IoHwAb_Digital_Read_DigitalSonarTrig(&level, &status);
	*value = level; 
	IoHwAb_DigitalSonarTrig_Locked = tempLock;
	SchM_Exit_IoHwAb_EA_0();
	return ret;
}

	


/* @req ARCIOHWAB001 */
Std_ReturnType IoHwAb_Digital_Write(IoHwAb_SignalType signal, IoHwAb_LevelType newValue)
{
	Std_ReturnType ret = E_NOT_OK;

	switch( signal ) {
	case IOHWAB_SIGNAL_DIGITALFRONTLED:
		ret = IoHwAb_Digital_Write_DigitalFrontLED(newValue);
		break;
	case IOHWAB_SIGNAL_DIGITALREARLED:
		ret = IoHwAb_Digital_Write_DigitalRearLED(newValue);
		break;
	case IOHWAB_SIGNAL_DIGITALSONARTRIG:
		ret = IoHwAb_Digital_Write_DigitalSonarTrig(newValue);
		break;
	default:
		IOHWAB_DET_REPORT_ERROR(IOHWAB_DIGITAL_WRITE_ID, IOHWAB_E_PARAM_SIGNAL);
		break;
	}
	return ret;
}

/* @req ARCIOHWAB001 */
Std_ReturnType IoHwAb_Digital_Read(IoHwAb_SignalType signal, IoHwAb_LevelType *value, IoHwAb_StatusType *status)
{
	Std_ReturnType ret = E_NOT_OK;

	switch( signal ) {
	case IOHWAB_SIGNAL_DIGITALSONARECHO:
		ret = IoHwAb_Digital_Read_DigitalSonarEcho(value, status);
		break;
	default:
		IOHWAB_DET_REPORT_ERROR(IOHWAB_DIGITAL_READ_ID, IOHWAB_E_PARAM_SIGNAL);
		break;
	}
	return ret;
}

