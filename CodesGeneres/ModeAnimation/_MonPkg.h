/*********************************************************************
	Rhapsody	: 9.0 
	Login		: mikae
	Component	: CodesGeneres 
	Configuration 	: ModeAnimation
	Model Element	: _MonPkg
//!	Generated Date	: Fri, 11, Nov 2022  
	File Path	: CodesGeneres\ModeAnimation\_MonPkg.h
*********************************************************************/

#ifndef _MonPkg_H
#define _MonPkg_H

//## auto_generated
#include <oxf\oxf.h>
//## auto_generated
#include <aom\aom.h>
//## auto_generated
#include "Windows.h"
//## auto_generated
#include "stdlib.h"
//## auto_generated
#include "stdio.h"
//## auto_generated
#include "string.h"
//## auto_generated
#include "stdint.h"
//## auto_generated
#include "tchar.h"
//## auto_generated
#include <oxf\event.h>
//## auto_generated
class _SysVehicule;

//#[ ignore
#define evPush__MonPkg_id 13401

#define evPushM__MonPkg_id 13402

#define tm500__MonPkg_id 13403

#define evOK__MonPkg_id 13404

#define evAppel__MonPkg_id 13405

#define evOkCar__MonPkg_id 13406

#define evAnnuleCar__MonPkg_id 13407

#define evSMS__MonPkg_id 13408

#define evAppelTel__MonPkg_id 13409

#define evAccepte__MonPkg_id 13410

#define evRefuse__MonPkg_id 13411

#define I__MonPkg_id 13412
//#]

//## package _MonPkg



//## event evPush()
class evPush : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevPush;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evPush();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevPush : virtual public AOMEvent {
    DECLARE_META_EVENT(evPush)
};
//#]
#endif // _OMINSTRUMENT

//## event evPushM()
class evPushM : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevPushM;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evPushM();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevPushM : virtual public AOMEvent {
    DECLARE_META_EVENT(evPushM)
};
//#]
#endif // _OMINSTRUMENT

//## event tm500()
class tm500 : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedtm500;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    tm500();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedtm500 : virtual public AOMEvent {
    DECLARE_META_EVENT(tm500)
};
//#]
#endif // _OMINSTRUMENT

//## event evOK()
class evOK : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevOK;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evOK();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevOK : virtual public AOMEvent {
    DECLARE_META_EVENT(evOK)
};
//#]
#endif // _OMINSTRUMENT

//## event evAppel()
class evAppel : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevAppel;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evAppel();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevAppel : virtual public AOMEvent {
    DECLARE_META_EVENT(evAppel)
};
//#]
#endif // _OMINSTRUMENT

//## event evOkCar()
class evOkCar : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevOkCar;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evOkCar();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevOkCar : virtual public AOMEvent {
    DECLARE_META_EVENT(evOkCar)
};
//#]
#endif // _OMINSTRUMENT

//## event evAnnuleCar()
class evAnnuleCar : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevAnnuleCar;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evAnnuleCar();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevAnnuleCar : virtual public AOMEvent {
    DECLARE_META_EVENT(evAnnuleCar)
};
//#]
#endif // _OMINSTRUMENT

//## event evSMS()
class evSMS : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevSMS;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evSMS();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevSMS : virtual public AOMEvent {
    DECLARE_META_EVENT(evSMS)
};
//#]
#endif // _OMINSTRUMENT

//## event evAppelTel()
class evAppelTel : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevAppelTel;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evAppelTel();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevAppelTel : virtual public AOMEvent {
    DECLARE_META_EVENT(evAppelTel)
};
//#]
#endif // _OMINSTRUMENT

//## event evAccepte()
class evAccepte : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevAccepte;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evAccepte();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevAccepte : virtual public AOMEvent {
    DECLARE_META_EVENT(evAccepte)
};
//#]
#endif // _OMINSTRUMENT

//## event evRefuse()
class evRefuse : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevRefuse;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evRefuse();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevRefuse : virtual public AOMEvent {
    DECLARE_META_EVENT(evRefuse)
};
//#]
#endif // _OMINSTRUMENT

//## event I()
class I : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedI;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    I();
    
    ////    Framework operations    ////
    
    //## statechart_method
    virtual bool isTypeOf(const short id) const;
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedI : virtual public AOMEvent {
    DECLARE_META_EVENT(I)
};
//#]
#endif // _OMINSTRUMENT

#endif
/*********************************************************************
	File Path	: CodesGeneres\ModeAnimation\_MonPkg.h
*********************************************************************/
