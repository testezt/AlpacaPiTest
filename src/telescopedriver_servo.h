//**************************************************************************
//*	Name:			telescopedriver_servo.h
//*
//*	Author:			Mark Sproul (C) 2022
//*
//*	Description:
//*
//*	Limitations:
//*
//*	Usage notes:
//*
//*	References:
//*****************************************************************************
//*	Edit History
//*****************************************************************************
//*	<MLS>	=	Mark L Sproul
//*****************************************************************************
//*	Mar 25,	2022	<MLS> Created telescopedriver_servo.h
//*****************************************************************************
//#include	"telescopedriver_servo.h"




#ifndef _TELESCOPE_DRIVER_H_
	#include	"telescopedriver.h"
#endif


void	CreateTelescopeServoObjects(void);

//**************************************************************************************
class TelescopeDriverServo: public TelescopeDriver
{
	public:

		//
		// Construction
		//
									TelescopeDriverServo(void);
		virtual						~TelescopeDriverServo(void);
		virtual	int32_t				RunStateMachine(void);

		virtual	void				OutputHTML_Part2(TYPE_GetPutRequestData *reqData);

		//*************************************************************************
		//*	DO NOT IMPLEMENT THE SYNCHRONOUS METHODS
		//*		Use the ASYNC methods instead
		//*		Alpaca cannot do synchronous and ASCOM/ALPACA are trying to eliminate all SYNC commands
		//*************************************************************************


//		//--------------------------------------------------------------------------------------------------
//		//*	these routines should be implemented by the sub-classes
//		//*	all have to return an Alpaca Error code
		virtual	TYPE_ASCOM_STATUS	Telescope_AbortSlew(	char *alpacaErrMsg);
		virtual	TYPE_ASCOM_STATUS	Telescope_FindHome(		char *alpacaErrMsg);
		virtual	TYPE_ASCOM_STATUS	Telescope_MoveAxis(		const int axisNum,
															const double moveRate_degPerSec,
															char *alpacaErrMsg);

		virtual	TYPE_ASCOM_STATUS	Telescope_Park(			char *alpacaErrMsg);
		virtual	TYPE_ASCOM_STATUS	Telescope_SetPark(		char *alpacaErrMsg);
		virtual	TYPE_ASCOM_STATUS	Telescope_SlewToAltAz(	const double	newAlt_Degrees,
															const double	newAz_Degrees,
															char *alpacaErrMsg);
//
		virtual	TYPE_ASCOM_STATUS	Telescope_SlewToRA_DEC(	const double	newRtAscen_Hours,
															const double	newDeclination_Degrees,
															char *alpacaErrMsg);

//
//
		virtual	TYPE_ASCOM_STATUS	Telescope_SyncToRA_DEC(	const double	newRtAscen_Hours,
															const double	newDeclination_Degrees,
															char *alpacaErrMsg);
		virtual	TYPE_ASCOM_STATUS	Telescope_TrackingOnOff(const bool newTrackingState,
															char *alpacaErrMsg);
//
//
		virtual	TYPE_ASCOM_STATUS	Telescope_UnPark(		char *alpacaErrMsg);
//
//
//		virtual	int					Telescope_GetLimitSwitchStatus(const TYPE_LIMITSWITCH whichLimit);
//		virtual	TYPE_PierSide		Telescope_GetPhysicalSideOfPier(void);

	private:
		bool				cServoConfigIsValid;
		void 				UpdateSlewingProperty(void);


};
