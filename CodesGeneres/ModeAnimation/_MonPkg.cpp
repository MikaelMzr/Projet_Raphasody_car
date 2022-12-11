/********************************************************************
	Rhapsody	: 9.0 
	Login		: mikae
	Component	: CodesGeneres 
	Configuration 	: ModeAnimation
	Model Element	: _MonPkg
//!	Generated Date	: Fri, 11, Nov 2022  
	File Path	: CodesGeneres\ModeAnimation\_MonPkg.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "_MonPkg.h"
//## auto_generated
#include "_SysVehicule.h"
//#[ ignore
#define evPush_SERIALIZE OM_NO_OP

#define evPush_UNSERIALIZE OM_NO_OP

#define evPush_CONSTRUCTOR evPush()

#define evPushM_SERIALIZE OM_NO_OP

#define evPushM_UNSERIALIZE OM_NO_OP

#define evPushM_CONSTRUCTOR evPushM()

#define tm500_SERIALIZE OM_NO_OP

#define tm500_UNSERIALIZE OM_NO_OP

#define tm500_CONSTRUCTOR tm500()

#define evOK_SERIALIZE OM_NO_OP

#define evOK_UNSERIALIZE OM_NO_OP

#define evOK_CONSTRUCTOR evOK()

#define evAppel_SERIALIZE OM_NO_OP

#define evAppel_UNSERIALIZE OM_NO_OP

#define evAppel_CONSTRUCTOR evAppel()

#define evOkCar_SERIALIZE OM_NO_OP

#define evOkCar_UNSERIALIZE OM_NO_OP

#define evOkCar_CONSTRUCTOR evOkCar()

#define evAnnuleCar_SERIALIZE OM_NO_OP

#define evAnnuleCar_UNSERIALIZE OM_NO_OP

#define evAnnuleCar_CONSTRUCTOR evAnnuleCar()

#define evSMS_SERIALIZE OM_NO_OP

#define evSMS_UNSERIALIZE OM_NO_OP

#define evSMS_CONSTRUCTOR evSMS()

#define evAppelTel_SERIALIZE OM_NO_OP

#define evAppelTel_UNSERIALIZE OM_NO_OP

#define evAppelTel_CONSTRUCTOR evAppelTel()

#define evAccepte_SERIALIZE OM_NO_OP

#define evAccepte_UNSERIALIZE OM_NO_OP

#define evAccepte_CONSTRUCTOR evAccepte()

#define evRefuse_SERIALIZE OM_NO_OP

#define evRefuse_UNSERIALIZE OM_NO_OP

#define evRefuse_CONSTRUCTOR evRefuse()

#define I_SERIALIZE OM_NO_OP

#define I_UNSERIALIZE OM_NO_OP

#define I_CONSTRUCTOR I()
//#]

//## package _MonPkg


#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes* /* aomsAttributes */);

IMPLEMENT_META_PACKAGE(_MonPkg, _MonPkg)

static void serializeGlobalVars(AOMSAttributes* /* aomsAttributes */) {
}
#endif // _OMINSTRUMENT

//## event evPush()
evPush::evPush() {
    NOTIFY_EVENT_CONSTRUCTOR(evPush)
    setId(evPush__MonPkg_id);
}

bool evPush::isTypeOf(const short id) const {
    return (evPush__MonPkg_id==id);
}

IMPLEMENT_META_EVENT_P(evPush, _MonPkg, _MonPkg, evPush())

//## event evPushM()
evPushM::evPushM() {
    NOTIFY_EVENT_CONSTRUCTOR(evPushM)
    setId(evPushM__MonPkg_id);
}

bool evPushM::isTypeOf(const short id) const {
    return (evPushM__MonPkg_id==id);
}

IMPLEMENT_META_EVENT_P(evPushM, _MonPkg, _MonPkg, evPushM())

//## event tm500()
tm500::tm500() {
    NOTIFY_EVENT_CONSTRUCTOR(tm500)
    setId(tm500__MonPkg_id);
}

bool tm500::isTypeOf(const short id) const {
    return (tm500__MonPkg_id==id);
}

IMPLEMENT_META_EVENT_P(tm500, _MonPkg, _MonPkg, tm500())

//## event evOK()
evOK::evOK() {
    NOTIFY_EVENT_CONSTRUCTOR(evOK)
    setId(evOK__MonPkg_id);
}

bool evOK::isTypeOf(const short id) const {
    return (evOK__MonPkg_id==id);
}

IMPLEMENT_META_EVENT_P(evOK, _MonPkg, _MonPkg, evOK())

//## event evAppel()
evAppel::evAppel() {
    NOTIFY_EVENT_CONSTRUCTOR(evAppel)
    setId(evAppel__MonPkg_id);
}

bool evAppel::isTypeOf(const short id) const {
    return (evAppel__MonPkg_id==id);
}

IMPLEMENT_META_EVENT_P(evAppel, _MonPkg, _MonPkg, evAppel())

//## event evOkCar()
evOkCar::evOkCar() {
    NOTIFY_EVENT_CONSTRUCTOR(evOkCar)
    setId(evOkCar__MonPkg_id);
}

bool evOkCar::isTypeOf(const short id) const {
    return (evOkCar__MonPkg_id==id);
}

IMPLEMENT_META_EVENT_P(evOkCar, _MonPkg, _MonPkg, evOkCar())

//## event evAnnuleCar()
evAnnuleCar::evAnnuleCar() {
    NOTIFY_EVENT_CONSTRUCTOR(evAnnuleCar)
    setId(evAnnuleCar__MonPkg_id);
}

bool evAnnuleCar::isTypeOf(const short id) const {
    return (evAnnuleCar__MonPkg_id==id);
}

IMPLEMENT_META_EVENT_P(evAnnuleCar, _MonPkg, _MonPkg, evAnnuleCar())

//## event evSMS()
evSMS::evSMS() {
    NOTIFY_EVENT_CONSTRUCTOR(evSMS)
    setId(evSMS__MonPkg_id);
}

bool evSMS::isTypeOf(const short id) const {
    return (evSMS__MonPkg_id==id);
}

IMPLEMENT_META_EVENT_P(evSMS, _MonPkg, _MonPkg, evSMS())

//## event evAppelTel()
evAppelTel::evAppelTel() {
    NOTIFY_EVENT_CONSTRUCTOR(evAppelTel)
    setId(evAppelTel__MonPkg_id);
}

bool evAppelTel::isTypeOf(const short id) const {
    return (evAppelTel__MonPkg_id==id);
}

IMPLEMENT_META_EVENT_P(evAppelTel, _MonPkg, _MonPkg, evAppelTel())

//## event evAccepte()
evAccepte::evAccepte() {
    NOTIFY_EVENT_CONSTRUCTOR(evAccepte)
    setId(evAccepte__MonPkg_id);
}

bool evAccepte::isTypeOf(const short id) const {
    return (evAccepte__MonPkg_id==id);
}

IMPLEMENT_META_EVENT_P(evAccepte, _MonPkg, _MonPkg, evAccepte())

//## event evRefuse()
evRefuse::evRefuse() {
    NOTIFY_EVENT_CONSTRUCTOR(evRefuse)
    setId(evRefuse__MonPkg_id);
}

bool evRefuse::isTypeOf(const short id) const {
    return (evRefuse__MonPkg_id==id);
}

IMPLEMENT_META_EVENT_P(evRefuse, _MonPkg, _MonPkg, evRefuse())

//## event I()
I::I() {
    NOTIFY_EVENT_CONSTRUCTOR(I)
    setId(I__MonPkg_id);
}

bool I::isTypeOf(const short id) const {
    return (I__MonPkg_id==id);
}

IMPLEMENT_META_EVENT_P(I, _MonPkg, _MonPkg, I())

/*********************************************************************
	File Path	: CodesGeneres\ModeAnimation\_MonPkg.cpp
*********************************************************************/
