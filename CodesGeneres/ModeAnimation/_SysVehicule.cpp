/********************************************************************
	Rhapsody	: 9.0 
	Login		: mikae
	Component	: CodesGeneres 
	Configuration 	: ModeAnimation
	Model Element	: _SysVehicule
//!	Generated Date	: Sat, 12, Nov 2022  
	File Path	: CodesGeneres\ModeAnimation\_SysVehicule.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## dependency _SysVehicule
#include "_SysVehicule.h"
//#[ ignore
#define _MonPkg__SysVehicule__SysVehicule_SERIALIZE OM_NO_OP

#define _MonPkg__SysVehicule_Operation_103_SERIALIZE OM_NO_OP

#define _MonPkg__SysVehicule_accelerer_SERIALIZE aomsmethod->addAttribute("accelPedal", x2String(accelPedal));

#define _MonPkg__SysVehicule_calcul_vitesse_distance_SERIALIZE aomsmethod->addAttribute("throttle", x2String(throttle));

#define _MonPkg__SysVehicule_freiner_SERIALIZE aomsmethod->addAttribute("brakePedal", x2String(brakePedal));

#define _MonPkg__SysVehicule_init_SERIALIZE OM_NO_OP

#define _MonPkg__SysVehicule_regulation_SERIALIZE OM_NO_OP

#define OMAnim__MonPkg__SysVehicule_setAccelPedal_double_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_accelPedal)

#define OMAnim__MonPkg__SysVehicule_setAccelPedal_double_SERIALIZE_RET_VAL

#define OMAnim__MonPkg__SysVehicule_setAlpha_int_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_alpha)

#define OMAnim__MonPkg__SysVehicule_setAlpha_int_SERIALIZE_RET_VAL

#define OMAnim__MonPkg__SysVehicule_setBluetooth_bool_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_bluetooth)

#define OMAnim__MonPkg__SysVehicule_setBluetooth_bool_SERIALIZE_RET_VAL

#define OMAnim__MonPkg__SysVehicule_setBouton_tel_int_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_bouton_tel)

#define OMAnim__MonPkg__SysVehicule_setBouton_tel_int_SERIALIZE_RET_VAL

#define OMAnim__MonPkg__SysVehicule_setBrakePedal_double_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_brakePedal)

#define OMAnim__MonPkg__SysVehicule_setBrakePedal_double_SERIALIZE_RET_VAL

#define OMAnim__MonPkg__SysVehicule_setLimiteur_bool_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_limiteur)

#define OMAnim__MonPkg__SysVehicule_setLimiteur_bool_SERIALIZE_RET_VAL

#define OMAnim__MonPkg__SysVehicule_setRegulateur_bool_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_regulateur)

#define OMAnim__MonPkg__SysVehicule_setRegulateur_bool_SERIALIZE_RET_VAL

#define OMAnim__MonPkg__SysVehicule_setVContact_int_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_vContact)

#define OMAnim__MonPkg__SysVehicule_setVContact_int_SERIALIZE_RET_VAL

#define OMAnim__MonPkg__SysVehicule_setVitesseLimite_int_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_vitesseLimite)

#define OMAnim__MonPkg__SysVehicule_setVitesseLimite_int_SERIALIZE_RET_VAL
//#]

//## package _MonPkg

//## class _SysVehicule
double _SysVehicule::accelerer(double accelPedal) {
    NOTIFY_OPERATION(accelerer, accelerer(double), 1, _MonPkg__SysVehicule_accelerer_SERIALIZE);
    //#[ operation accelerer(double)
    if(throttle<(MAX_THROTTLE-(accelPedal/3)))
        		throttle+=accelPedal/3;	
        	else 
        		 throttle=MAX_THROTTLE;   
        		 
    return throttle;
    //#]
}

void _SysVehicule::calcul_vitesse_distance(double& throttle) {
    NOTIFY_OPERATION(calcul_vitesse_distance, calcul_vitesse_distance(double&), 1, _MonPkg__SysVehicule_calcul_vitesse_distance_SERIALIZE);
    //#[ operation calcul_vitesse_distance(double)
    
    fspeed=fspeed-1.5*sin(alpha*3.14/180)+((throttle-fspeed/airResistance-2*brakePedal))/5;
    
    if(fspeed>MAX_SPEED) fspeed=MAX_SPEED;
    if(fspeed<0) fspeed=0;
    
    fdist=fdist+(fspeed/36.0)/5.0;
    
    speed=(int)fspeed;
    
    distance=(int)fdist;
    
    if(throttle>0.0) throttle-=(0.5/10.0);  
    
    
    
    //#]
}

double _SysVehicule::freiner(double brakePedal) {
    NOTIFY_OPERATION(freiner, freiner(double), 1, _MonPkg__SysVehicule_freiner_SERIALIZE);
    //#[ operation freiner(double)
     //if(throttle>(2.0*brakePedal))
     if(throttle>0.0)  
      {
        	throttle -= (brakePedal/2);
      }
     else throttle = 0.0;       
      
     return throttle;
    //#]
}

void _SysVehicule::init() {
    NOTIFY_OPERATION(init, init(), 0, _MonPkg__SysVehicule_init_SERIALIZE);
    //#[ operation init()
    fdist=0.0;
    fspeed=0.0; 
    throttle=0.0;   
    speed=0;
    airResistance=MAX_SPEED/MAX_THROTTLE;
    brakePedal=0;   
    accelPedal=0;     
    distance=0;
    vBatterie=100;
    //#]
}

_SysVehicule::_SysVehicule(IOxfActive* theActiveContext) : Alarme(false), LED(false), MAX_BRAKE(10), MAX_SPEED(120), MAX_THROTTLE(10.0), MemoryAccel(0.0), Voyant(false), _simu(true), accelPedal(0.0), affiche_kit_b_car(false), airResistance(0.0), alpha(0), appel_en_cours(false), bluetooth(false), brakePedal(0.0), cpt_sms(0), distance(0), error(0.0), fdist(0.0), fspeed(0.0), ignition(false), limiteur(false), regulateur(false), speed(0), steady(0.0), throttle(0.0), vContact(0), vJum(false), vSonnerie(false), vSonnerieTel(false), vitesseConsigne(0), vitesseLimite(0) {
    NOTIFY_ACTIVE_CONSTRUCTOR(_SysVehicule, _SysVehicule(), 0, _MonPkg__SysVehicule__SysVehicule_SERIALIZE);
    setActiveContext(this, true);
    initStatechart();
}

_SysVehicule::~_SysVehicule() {
    NOTIFY_DESTRUCTOR(~_SysVehicule, true);
    cancelTimeouts();
}

int _SysVehicule::getMAX_BRAKE() {
    return MAX_BRAKE;
}

void _SysVehicule::setMAX_BRAKE(int p_MAX_BRAKE) {
    MAX_BRAKE = p_MAX_BRAKE;
}

int _SysVehicule::getMAX_SPEED() {
    return MAX_SPEED;
}

void _SysVehicule::setMAX_SPEED(int p_MAX_SPEED) {
    MAX_SPEED = p_MAX_SPEED;
}

double _SysVehicule::getMAX_THROTTLE() {
    return MAX_THROTTLE;
}

void _SysVehicule::setMAX_THROTTLE(double p_MAX_THROTTLE) {
    MAX_THROTTLE = p_MAX_THROTTLE;
}

bool _SysVehicule::get_simu() {
    return _simu;
}

void _SysVehicule::set_simu(bool p__simu) {
    _simu = p__simu;
}

double _SysVehicule::getAccelPedal() {
    return accelPedal;
}

void _SysVehicule::setAccelPedal(double p_accelPedal) {
    accelPedal = p_accelPedal;
    NOTIFY_SET_OPERATION;
}

double _SysVehicule::getAirResistance() {
    return airResistance;
}

void _SysVehicule::setAirResistance(double p_airResistance) {
    airResistance = p_airResistance;
}

int _SysVehicule::getAlpha() {
    return alpha;
}

void _SysVehicule::setAlpha(int p_alpha) {
    alpha = p_alpha;
    NOTIFY_SET_OPERATION;
}

double _SysVehicule::getBrakePedal() {
    return brakePedal;
}

void _SysVehicule::setBrakePedal(double p_brakePedal) {
    brakePedal = p_brakePedal;
    NOTIFY_SET_OPERATION;
}

int _SysVehicule::getDistance() {
    return distance;
}

void _SysVehicule::setDistance(int p_distance) {
    distance = p_distance;
    NOTIFY_SET_OPERATION;
}

double _SysVehicule::getError() {
    return error;
}

void _SysVehicule::setError(double p_error) {
    error = p_error;
}

double _SysVehicule::getFdist() {
    return fdist;
}

void _SysVehicule::setFdist(double p_fdist) {
    fdist = p_fdist;
}

double _SysVehicule::getFspeed() {
    return fspeed;
}

void _SysVehicule::setFspeed(double p_fspeed) {
    fspeed = p_fspeed;
}

bool _SysVehicule::getIgnition() {
    return ignition;
}

int _SysVehicule::getSpeed() {
    return speed;
}

double _SysVehicule::getSteady() {
    return steady;
}

void _SysVehicule::setSteady(double p_steady) {
    steady = p_steady;
}

double _SysVehicule::getThrottle() {
    return throttle;
}

int _SysVehicule::getVitesseConsigne() {
    return vitesseConsigne;
}

void _SysVehicule::setVitesseConsigne(int p_vitesseConsigne) {
    vitesseConsigne = p_vitesseConsigne;
    NOTIFY_SET_OPERATION;
}

bool _SysVehicule::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    if(done)
        {
            startDispatching();
        }
    return done;
}

void _SysVehicule::setIgnition(bool p_ignition) {
    ignition = p_ignition;
}

void _SysVehicule::setSpeed(int p_speed) {
    speed = p_speed;
    NOTIFY_SET_OPERATION;
}

void _SysVehicule::setThrottle(double p_throttle) {
    throttle = p_throttle;
    NOTIFY_SET_OPERATION;
}

void _SysVehicule::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    state_84_subState = OMNonState;
    state_84_active = OMNonState;
    state_90_subState = OMNonState;
    state_90_active = OMNonState;
    state_90_timeout = NULL;
    state_89_subState = OMNonState;
    state_89_active = OMNonState;
    state_83_subState = OMNonState;
    state_83_active = OMNonState;
    state_9_subState = OMNonState;
    state_9_active = OMNonState;
    state_9_timeout = NULL;
    Allumage_subState = OMNonState;
    Allumage_timeout = NULL;
    state_67_subState = OMNonState;
    state_67_active = OMNonState;
    state_67_timeout = NULL;
    state_49_subState = OMNonState;
    state_49_active = OMNonState;
    state_49_timeout = NULL;
    state_32_subState = OMNonState;
    state_32_active = OMNonState;
    state_32_timeout = NULL;
    state_2_subState = OMNonState;
    state_2_active = OMNonState;
    state_13_subState = OMNonState;
    state_13_timeout = NULL;
    state_1_subState = OMNonState;
    state_1_active = OMNonState;
    state_1_timeout = NULL;
}

void _SysVehicule::cancelTimeouts() {
    cancel(state_90_timeout);
    cancel(state_9_timeout);
    cancel(Allumage_timeout);
    cancel(state_67_timeout);
    cancel(state_49_timeout);
    cancel(state_32_timeout);
    cancel(state_13_timeout);
    cancel(state_1_timeout);
}

bool _SysVehicule::cancelTimeout(const IOxfTimeout* arg) {
    bool res = false;
    if(state_90_timeout == arg)
        {
            state_90_timeout = NULL;
            res = true;
        }
    if(state_9_timeout == arg)
        {
            state_9_timeout = NULL;
            res = true;
        }
    if(Allumage_timeout == arg)
        {
            Allumage_timeout = NULL;
            res = true;
        }
    if(state_67_timeout == arg)
        {
            state_67_timeout = NULL;
            res = true;
        }
    if(state_49_timeout == arg)
        {
            state_49_timeout = NULL;
            res = true;
        }
    if(state_32_timeout == arg)
        {
            state_32_timeout = NULL;
            res = true;
        }
    if(state_13_timeout == arg)
        {
            state_13_timeout = NULL;
            res = true;
        }
    if(state_1_timeout == arg)
        {
            state_1_timeout = NULL;
            res = true;
        }
    return res;
}

void _SysVehicule::regulation() {
    NOTIFY_OPERATION(regulation, regulation(), 0, _MonPkg__SysVehicule_regulation_SERIALIZE);
    //#[ operation regulation()
    if(vitesseConsigne<0){ //eviter d'avoir une vitesse consigne négative
       vitesseConsigne=0;
    }
    error  = (double) (5*(vitesseConsigne - speed) / 6.0);
    steady = (double) (vitesseConsigne / 12.0);
    throttle = steady+error;
    
    //#]
}

bool _SysVehicule::getRegulateur() {
    return regulateur;
}

void _SysVehicule::setRegulateur(bool p_regulateur) {
    regulateur = p_regulateur;
    NOTIFY_SET_OPERATION;
}

void _SysVehicule::Operation_103() {
    NOTIFY_OPERATION(Operation_103, Operation_103(), 0, _MonPkg__SysVehicule_Operation_103_SERIALIZE);
    //#[ operation Operation_103()
    //#]
}

bool _SysVehicule::getAlarme() {
    return Alarme;
}

void _SysVehicule::setAlarme(bool p_Alarme) {
    Alarme = p_Alarme;
}

bool _SysVehicule::getLED() {
    return LED;
}

void _SysVehicule::setLED(bool p_LED) {
    LED = p_LED;
    NOTIFY_SET_OPERATION;
}

double _SysVehicule::getMemoryAccel() {
    return MemoryAccel;
}

void _SysVehicule::setMemoryAccel(double p_MemoryAccel) {
    MemoryAccel = p_MemoryAccel;
    NOTIFY_SET_OPERATION;
}

bool _SysVehicule::getVoyant() {
    return Voyant;
}

void _SysVehicule::setVoyant(bool p_Voyant) {
    Voyant = p_Voyant;
}

int _SysVehicule::getAugmentation_int_0() {
    return augmentation_int_0;
}

void _SysVehicule::setAugmentation_int_0(int p_augmentation_int_0) {
    augmentation_int_0 = p_augmentation_int_0;
}

int _SysVehicule::getDiminution_int_0() {
    return diminution_int_0;
}

void _SysVehicule::setDiminution_int_0(int p_diminution_int_0) {
    diminution_int_0 = p_diminution_int_0;
}

bool _SysVehicule::getLimiteur() {
    return limiteur;
}

void _SysVehicule::setLimiteur(bool p_limiteur) {
    limiteur = p_limiteur;
    NOTIFY_SET_OPERATION;
}

int _SysVehicule::getVitesseLimite() {
    return vitesseLimite;
}

void _SysVehicule::setVitesseLimite(int p_vitesseLimite) {
    vitesseLimite = p_vitesseLimite;
    NOTIFY_SET_OPERATION;
}

bool _SysVehicule::getAffiche_kit_b_car() {
    return affiche_kit_b_car;
}

void _SysVehicule::setAffiche_kit_b_car(bool p_affiche_kit_b_car) {
    affiche_kit_b_car = p_affiche_kit_b_car;
    NOTIFY_SET_OPERATION;
}

bool _SysVehicule::getBluetooth() {
    return bluetooth;
}

void _SysVehicule::setBluetooth(bool p_bluetooth) {
    bluetooth = p_bluetooth;
    NOTIFY_SET_OPERATION;
}

int _SysVehicule::getBouton_tel() {
    return bouton_tel;
}

void _SysVehicule::setBouton_tel(int p_bouton_tel) {
    bouton_tel = p_bouton_tel;
    NOTIFY_SET_OPERATION;
}

int _SysVehicule::getCpt_sms() {
    return cpt_sms;
}

void _SysVehicule::setCpt_sms(int p_cpt_sms) {
    cpt_sms = p_cpt_sms;
    NOTIFY_SET_OPERATION;
}

int _SysVehicule::getVContact() {
    return vContact;
}

void _SysVehicule::setVContact(int p_vContact) {
    vContact = p_vContact;
    NOTIFY_SET_OPERATION;
}

bool _SysVehicule::getVJum() {
    return vJum;
}

void _SysVehicule::setVJum(bool p_vJum) {
    vJum = p_vJum;
    NOTIFY_SET_OPERATION;
}

bool _SysVehicule::getVSonnerie() {
    return vSonnerie;
}

void _SysVehicule::setVSonnerie(bool p_vSonnerie) {
    vSonnerie = p_vSonnerie;
    NOTIFY_SET_OPERATION;
}

bool _SysVehicule::getVSonnerieTel() {
    return vSonnerieTel;
}

void _SysVehicule::setVSonnerieTel(bool p_vSonnerieTel) {
    vSonnerieTel = p_vSonnerieTel;
    NOTIFY_SET_OPERATION;
}

bool _SysVehicule::getAppel_en_cours() {
    return appel_en_cours;
}

void _SysVehicule::setAppel_en_cours(bool p_appel_en_cours) {
    appel_en_cours = p_appel_en_cours;
    NOTIFY_SET_OPERATION;
}

int _SysVehicule::getVBatterie() {
    return vBatterie;
}

void _SysVehicule::setVBatterie(int p_vBatterie) {
    vBatterie = p_vBatterie;
    NOTIFY_SET_OPERATION;
}

int _SysVehicule::getVBatterie_tel() {
    return vBatterie_tel;
}

void _SysVehicule::setVBatterie_tel(int p_vBatterie_tel) {
    vBatterie_tel = p_vBatterie_tel;
    NOTIFY_SET_OPERATION;
}

void _SysVehicule::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        rootStateEntDef();
    }
}

void _SysVehicule::rootStateEntDef() {
    NOTIFY_TRANSITION_STARTED("56");
    state_82_entDef();
    NOTIFY_TRANSITION_TERMINATED("56");
}

IOxfReactive::TakeEventStatus _SysVehicule::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    // State state_82
    if(rootState_active == state_82)
        {
            res = state_82_processEvent();
        }
    return res;
}

void _SysVehicule::state_82_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_82");
    rootState_subState = state_82;
    rootState_active = state_82;
    state_83_entDef();
    state_84_entDef();
}

void _SysVehicule::state_82_exit() {
    switch (state_83_subState) {
        // State state_0
        case state_0:
        {
            state_0_exit();
        }
        break;
        // State state_4
        case state_4:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_4");
        }
        break;
        default:
            break;
    }
    state_83_subState = OMNonState;
    NOTIFY_STATE_EXITED("ROOT.state_82.state_83");
    state_84_exit();
    
    NOTIFY_STATE_EXITED("ROOT.state_82");
}

IOxfReactive::TakeEventStatus _SysVehicule::state_82_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    // State state_83
    if(state_83_processEvent() != eventNotConsumed)
        {
            res = eventConsumed;
            if(!IS_IN(state_82))
                {
                    return res;
                }
        }
    // State state_84
    if(state_84_processEvent() != eventNotConsumed)
        {
            res = eventConsumed;
            if(!IS_IN(state_82))
                {
                    return res;
                }
        }
    
    return res;
}

void _SysVehicule::state_84_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_84");
    NOTIFY_TRANSITION_STARTED("55");
    Telephone_entDef();
    NOTIFY_TRANSITION_TERMINATED("55");
}

void _SysVehicule::state_84_exit() {
    // State Telephone
    if(state_84_subState == Telephone)
        {
            Telephone_exit();
        }
    state_84_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_82.state_84");
}

IOxfReactive::TakeEventStatus _SysVehicule::state_84_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    // State Telephone
    if(state_84_active == Telephone)
        {
            res = Telephone_processEvent();
        }
    return res;
}

void _SysVehicule::Telephone_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone");
    state_84_subState = Telephone;
    state_84_active = Telephone;
    state_89_entDef();
    state_90_entDef();
}

void _SysVehicule::Telephone_exit() {
    state_89_exit();
    state_90_exit();
    
    NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone");
}

IOxfReactive::TakeEventStatus _SysVehicule::Telephone_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    // State state_89
    if(state_89_processEvent() != eventNotConsumed)
        {
            res = eventConsumed;
            if(!IS_IN(Telephone))
                {
                    return res;
                }
        }
    // State state_90
    if(state_90_processEvent() != eventNotConsumed)
        {
            res = eventConsumed;
            if(!IS_IN(Telephone))
                {
                    return res;
                }
        }
    
    return res;
}

void _SysVehicule::state_90_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_90");
    NOTIFY_TRANSITION_STARTED("63");
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_90.state_94");
    pushNullTransition();
    state_90_subState = state_94;
    state_90_active = state_94;
    state_90_timeout = scheduleTimeout(120000, "ROOT.state_82.state_84.Telephone.state_90.state_94");
    NOTIFY_TRANSITION_TERMINATED("63");
}

void _SysVehicule::state_90_exit() {
    switch (state_90_subState) {
        // State state_94
        case state_94:
        {
            popNullTransition();
            cancel(state_90_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_90.state_94");
        }
        break;
        // State state_95
        case state_95:
        {
            cancel(state_90_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_90.state_95");
        }
        break;
        // State state_96
        case state_96:
        {
            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_90.state_96");
        }
        break;
        // State no_battery
        case no_battery:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_90.no_battery");
        }
        break;
        default:
            break;
    }
    state_90_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_90");
}

IOxfReactive::TakeEventStatus _SysVehicule::state_90_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (state_90_active) {
        // State state_94
        case state_94:
        {
            res = state_94_handleEvent();
        }
        break;
        // State state_95
        case state_95:
        {
            res = state_95_handleEvent();
        }
        break;
        // State state_96
        case state_96:
        {
            if(IS_EVENT_TYPE_OF(evRefuse__MonPkg_id))
                {
                    NOTIFY_TRANSITION_STARTED("67");
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_90.state_96");
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_90.state_94");
                    pushNullTransition();
                    state_90_subState = state_94;
                    state_90_active = state_94;
                    state_90_timeout = scheduleTimeout(120000, "ROOT.state_82.state_84.Telephone.state_90.state_94");
                    NOTIFY_TRANSITION_TERMINATED("67");
                    res = eventConsumed;
                }
            
            
        }
        break;
        // State no_battery
        case no_battery:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 74 
                    if(vBatterie>0)
                        {
                            NOTIFY_TRANSITION_STARTED("74");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_90.no_battery");
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_90.state_94");
                            pushNullTransition();
                            state_90_subState = state_94;
                            state_90_active = state_94;
                            state_90_timeout = scheduleTimeout(120000, "ROOT.state_82.state_84.Telephone.state_90.state_94");
                            NOTIFY_TRANSITION_TERMINATED("74");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        default:
            break;
    }
    return res;
}

IOxfReactive::TakeEventStatus _SysVehicule::state_95_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(evAccepte__MonPkg_id))
        {
            NOTIFY_TRANSITION_STARTED("66");
            cancel(state_90_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_90.state_95");
            //#[ transition 66 
            PlaySound(NULL, 0, 0);
            //#]
            NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_90.state_96");
            state_90_subState = state_96;
            state_90_active = state_96;
            NOTIFY_TRANSITION_TERMINATED("66");
            res = eventConsumed;
        }
    else if(IS_EVENT_TYPE_OF(evRefuse__MonPkg_id))
        {
            NOTIFY_TRANSITION_STARTED("68");
            cancel(state_90_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_90.state_95");
            //#[ transition 68 
            PlaySound(NULL, 0, 0);
            //#]
            NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_90.state_94");
            pushNullTransition();
            state_90_subState = state_94;
            state_90_active = state_94;
            state_90_timeout = scheduleTimeout(120000, "ROOT.state_82.state_84.Telephone.state_90.state_94");
            NOTIFY_TRANSITION_TERMINATED("68");
            res = eventConsumed;
        }
    else if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
        {
            if(getCurrentEvent() == state_90_timeout)
                {
                    NOTIFY_TRANSITION_STARTED("65");
                    cancel(state_90_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_90.state_95");
                    //#[ transition 65 
                    vSonnerieTel=!vSonnerieTel;
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_90.state_95");
                    state_90_subState = state_95;
                    state_90_active = state_95;
                    state_90_timeout = scheduleTimeout(100, "ROOT.state_82.state_84.Telephone.state_90.state_95");
                    NOTIFY_TRANSITION_TERMINATED("65");
                    res = eventConsumed;
                }
        }
    
    
    return res;
}

IOxfReactive::TakeEventStatus _SysVehicule::state_94_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
        {
            if(getCurrentEvent() == state_90_timeout)
                {
                    NOTIFY_TRANSITION_STARTED("72");
                    popNullTransition();
                    cancel(state_90_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_90.state_94");
                    //#[ transition 72 
                    vBatterie-=1;
                    if(vBatterie<0){vBatterie=0;}
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_90.state_94");
                    pushNullTransition();
                    state_90_subState = state_94;
                    state_90_active = state_94;
                    state_90_timeout = scheduleTimeout(120000, "ROOT.state_82.state_84.Telephone.state_90.state_94");
                    NOTIFY_TRANSITION_TERMINATED("72");
                    res = eventConsumed;
                }
        }
    else if(IS_EVENT_TYPE_OF(OMNullEventId))
        {
            //## transition 73 
            if(vBatterie==0)
                {
                    NOTIFY_TRANSITION_STARTED("73");
                    popNullTransition();
                    cancel(state_90_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_90.state_94");
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_90.no_battery");
                    pushNullTransition();
                    state_90_subState = no_battery;
                    state_90_active = no_battery;
                    NOTIFY_TRANSITION_TERMINATED("73");
                    res = eventConsumed;
                }
        }
    else if(IS_EVENT_TYPE_OF(evAppel__MonPkg_id))
        {
            //## transition 64 
            if(IS_IN(state_97) || IS_IN(on) || IS_IN(off))
                {
                    NOTIFY_TRANSITION_STARTED("64");
                    popNullTransition();
                    cancel(state_90_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_90.state_94");
                    //#[ transition 64 
                    PlaySound(TEXT("sonnerie.wav"), NULL, SND_LOOP | SND_ASYNC);
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_90.state_95");
                    state_90_subState = state_95;
                    state_90_active = state_95;
                    state_90_timeout = scheduleTimeout(100, "ROOT.state_82.state_84.Telephone.state_90.state_95");
                    NOTIFY_TRANSITION_TERMINATED("64");
                    res = eventConsumed;
                }
        }
    
    
    return res;
}

void _SysVehicule::state_89_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_89");
    NOTIFY_TRANSITION_STARTED("41");
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_89.state_73");
    pushNullTransition();
    state_89_subState = state_73;
    state_89_active = state_73;
    NOTIFY_TRANSITION_TERMINATED("41");
}

void _SysVehicule::state_89_exit() {
    switch (state_89_subState) {
        // State state_73
        case state_73:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_89.state_73");
        }
        break;
        // State state_74
        case state_74:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_89.state_74");
        }
        break;
        // State state_75
        case state_75:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_89.state_75");
        }
        break;
        // State jumelage
        case jumelage:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_89.jumelage");
        }
        break;
        // State state_77
        case state_77:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_89.state_77");
        }
        break;
        // State state_78
        case state_78:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_89.state_78");
        }
        break;
        // State state_79
        case state_79:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_89.state_79");
        }
        break;
        // State jumele_tel
        case jumele_tel:
        {
            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_89.jumele_tel");
        }
        break;
        default:
            break;
    }
    state_89_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_89");
}

IOxfReactive::TakeEventStatus _SysVehicule::state_89_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (state_89_active) {
        // State state_73
        case state_73:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 42 
                    if(bluetooth && IS_IN(state_94))
                        {
                            NOTIFY_TRANSITION_STARTED("42");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_89.state_73");
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_89.state_74");
                            pushNullTransition();
                            state_89_subState = state_74;
                            state_89_active = state_74;
                            NOTIFY_TRANSITION_TERMINATED("42");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        // State state_74
        case state_74:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 43 
                    if(!bluetooth)
                        {
                            NOTIFY_TRANSITION_STARTED("43");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_89.state_74");
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_89.state_73");
                            pushNullTransition();
                            state_89_subState = state_73;
                            state_89_active = state_73;
                            NOTIFY_TRANSITION_TERMINATED("43");
                            res = eventConsumed;
                        }
                    else
                        {
                            //## transition 44 
                            if(IS_IN(on))
                                {
                                    NOTIFY_TRANSITION_STARTED("44");
                                    popNullTransition();
                                    NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_89.state_74");
                                    //#[ transition 44 
                                    affiche_kit_b_car=true;
                                    //#]
                                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_89.state_75");
                                    pushNullTransition();
                                    state_89_subState = state_75;
                                    state_89_active = state_75;
                                    NOTIFY_TRANSITION_TERMINATED("44");
                                    res = eventConsumed;
                                }
                        }
                }
            
            
        }
        break;
        // State state_75
        case state_75:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 45 
                    if(IS_IN(off))
                        {
                            NOTIFY_TRANSITION_STARTED("45");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_89.state_75");
                            //#[ transition 45 
                            affiche_kit_b_car=false;
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_89.state_74");
                            pushNullTransition();
                            state_89_subState = state_74;
                            state_89_active = state_74;
                            NOTIFY_TRANSITION_TERMINATED("45");
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(evOK__MonPkg_id))
                {
                    NOTIFY_TRANSITION_STARTED("46");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_89.state_75");
                    //#[ transition 46 
                    bouton_tel=0;
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_89.jumelage");
                    pushNullTransition();
                    state_89_subState = jumelage;
                    state_89_active = jumelage;
                    NOTIFY_TRANSITION_TERMINATED("46");
                    res = eventConsumed;
                }
            
            
        }
        break;
        // State jumelage
        case jumelage:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 47 
                    if(bouton_tel==1)
                        {
                            NOTIFY_TRANSITION_STARTED("47");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_89.jumelage");
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_89.state_77");
                            pushNullTransition();
                            state_89_subState = state_77;
                            state_89_active = state_77;
                            NOTIFY_TRANSITION_TERMINATED("47");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        // State state_77
        case state_77:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 48 
                    if(bouton_tel==2)
                        {
                            NOTIFY_TRANSITION_STARTED("48");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_89.state_77");
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_89.state_78");
                            pushNullTransition();
                            state_89_subState = state_78;
                            state_89_active = state_78;
                            NOTIFY_TRANSITION_TERMINATED("48");
                            res = eventConsumed;
                        }
                    else
                        {
                            //## transition 51 
                            if(bouton_tel!=1)
                                {
                                    NOTIFY_TRANSITION_STARTED("51");
                                    popNullTransition();
                                    NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_89.state_77");
                                    //#[ transition 51 
                                    bouton_tel=0;
                                    //#]
                                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_89.jumelage");
                                    pushNullTransition();
                                    state_89_subState = jumelage;
                                    state_89_active = jumelage;
                                    NOTIFY_TRANSITION_TERMINATED("51");
                                    res = eventConsumed;
                                }
                        }
                }
            
            
        }
        break;
        // State state_78
        case state_78:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 49 
                    if(bouton_tel==3)
                        {
                            NOTIFY_TRANSITION_STARTED("49");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_89.state_78");
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_89.state_79");
                            pushNullTransition();
                            state_89_subState = state_79;
                            state_89_active = state_79;
                            NOTIFY_TRANSITION_TERMINATED("49");
                            res = eventConsumed;
                        }
                    else
                        {
                            //## transition 52 
                            if(bouton_tel!=2)
                                {
                                    NOTIFY_TRANSITION_STARTED("52");
                                    popNullTransition();
                                    NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_89.state_78");
                                    //#[ transition 52 
                                    bouton_tel=0;
                                    //#]
                                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_89.jumelage");
                                    pushNullTransition();
                                    state_89_subState = jumelage;
                                    state_89_active = jumelage;
                                    NOTIFY_TRANSITION_TERMINATED("52");
                                    res = eventConsumed;
                                }
                        }
                }
            
            
        }
        break;
        // State state_79
        case state_79:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 50 
                    if(bouton_tel==4)
                        {
                            NOTIFY_TRANSITION_STARTED("50");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_89.state_79");
                            //#[ transition 50 
                            vJum=true;
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_89.jumele_tel");
                            state_89_subState = jumele_tel;
                            state_89_active = jumele_tel;
                            NOTIFY_TRANSITION_TERMINATED("50");
                            res = eventConsumed;
                        }
                    else
                        {
                            //## transition 53 
                            if(bouton_tel!=3)
                                {
                                    NOTIFY_TRANSITION_STARTED("53");
                                    popNullTransition();
                                    NOTIFY_STATE_EXITED("ROOT.state_82.state_84.Telephone.state_89.state_79");
                                    //#[ transition 53 
                                    bouton_tel=0;
                                    //#]
                                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_84.Telephone.state_89.jumelage");
                                    pushNullTransition();
                                    state_89_subState = jumelage;
                                    state_89_active = jumelage;
                                    NOTIFY_TRANSITION_TERMINATED("53");
                                    res = eventConsumed;
                                }
                        }
                }
            
            
        }
        break;
        
        default:
            break;
    }
    return res;
}

void _SysVehicule::state_83_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83");
    NOTIFY_TRANSITION_STARTED("1");
    //#[ transition 1 
    init();
    //#]
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_4");
    pushNullTransition();
    state_83_subState = state_4;
    state_83_active = state_4;
    NOTIFY_TRANSITION_TERMINATED("1");
}

IOxfReactive::TakeEventStatus _SysVehicule::state_83_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (state_83_active) {
        // State state_0
        case state_0:
        {
            res = state_0_processEvent();
        }
        break;
        // State state_4
        case state_4:
        {
            res = state_4_handleEvent();
        }
        break;
        default:
            break;
    }
    return res;
}

IOxfReactive::TakeEventStatus _SysVehicule::state_4TakeNull() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    NOTIFY_TRANSITION_STARTED("0");
    popNullTransition();
    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_4");
    state_0_entDef();
    NOTIFY_TRANSITION_TERMINATED("0");
    res = eventConsumed;
    return res;
}

IOxfReactive::TakeEventStatus _SysVehicule::state_4_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMNullEventId))
        {
            res = state_4TakeNull();
        }
    
    
    return res;
}

void _SysVehicule::state_0_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0");
    state_83_subState = state_0;
    state_83_active = state_0;
    state_1_entDef();
    state_2_entDef();
    state_9_entDef();
    state_32_entDef();
    state_49_entDef();
    state_67_entDef();
}

void _SysVehicule::state_0_exit() {
    switch (state_1_subState) {
        // State state_23
        case state_23:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_1.state_23");
        }
        break;
        // State state_24
        case state_24:
        {
            popNullTransition();
            cancel(state_1_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_1.state_24");
        }
        break;
        // State state_31
        case state_31:
        {
            popNullTransition();
            cancel(state_1_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_1.state_31");
        }
        break;
        default:
            break;
    }
    state_1_subState = OMNonState;
    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_1");
    state_2_exit();
    switch (state_9_subState) {
        // State Allumage
        case Allumage:
        {
            popNullTransition();
            switch (Allumage_subState) {
                // State Acceleration
                case Acceleration:
                {
                    popNullTransition();
                    cancel(Allumage_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_9.Allumage.Acceleration");
                }
                break;
                // State Freinage
                case Freinage:
                {
                    popNullTransition();
                    cancel(Allumage_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_9.Allumage.Freinage");
                }
                break;
                default:
                    break;
            }
            Allumage_subState = OMNonState;
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_9.Allumage");
        }
        break;
        // State contact
        case contact:
        {
            popNullTransition();
            cancel(state_9_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_9.contact");
        }
        break;
        default:
            break;
    }
    state_9_subState = OMNonState;
    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_9");
    state_32_exit();
    state_49_exit();
    state_67_exit();
    
    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0");
}

IOxfReactive::TakeEventStatus _SysVehicule::state_0_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    // State state_1
    if(state_1_processEvent() != eventNotConsumed)
        {
            res = eventConsumed;
            if(!IS_IN(state_0))
                {
                    return res;
                }
        }
    // State state_2
    if(state_2_processEvent() != eventNotConsumed)
        {
            res = eventConsumed;
            if(!IS_IN(state_0))
                {
                    return res;
                }
        }
    // State state_9
    if(state_9_processEvent() != eventNotConsumed)
        {
            res = eventConsumed;
            if(!IS_IN(state_0))
                {
                    return res;
                }
        }
    // State state_32
    if(state_32_processEvent() != eventNotConsumed)
        {
            res = eventConsumed;
            if(!IS_IN(state_0))
                {
                    return res;
                }
        }
    // State state_49
    if(state_49_processEvent() != eventNotConsumed)
        {
            res = eventConsumed;
            if(!IS_IN(state_0))
                {
                    return res;
                }
        }
    // State state_67
    if(state_67_processEvent() != eventNotConsumed)
        {
            res = eventConsumed;
            if(!IS_IN(state_0))
                {
                    return res;
                }
        }
    
    return res;
}

void _SysVehicule::state_9_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_9");
    NOTIFY_TRANSITION_STARTED("11");
    Allumage_entDef();
    NOTIFY_TRANSITION_TERMINATED("11");
}

IOxfReactive::TakeEventStatus _SysVehicule::state_9_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (state_9_active) {
        // State Acceleration
        case Acceleration:
        {
            res = Acceleration_handleEvent();
        }
        break;
        // State Freinage
        case Freinage:
        {
            res = Freinage_handleEvent();
        }
        break;
        // State contact
        case contact:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == state_9_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("12");
                            popNullTransition();
                            cancel(state_9_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_9.contact");
                            //#[ transition 12 
                            freiner(brakePedal);
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_9.contact");
                            pushNullTransition();
                            state_9_subState = contact;
                            state_9_active = contact;
                            state_9_timeout = scheduleTimeout(200, "ROOT.state_82.state_83.state_0.state_9.contact");
                            NOTIFY_TRANSITION_TERMINATED("12");
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 10 
                    if(vContact==2)
                        {
                            NOTIFY_TRANSITION_STARTED("10");
                            popNullTransition();
                            cancel(state_9_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_9.contact");
                            Allumage_entDef();
                            NOTIFY_TRANSITION_TERMINATED("10");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        default:
            break;
    }
    return res;
}

void _SysVehicule::Allumage_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_9.Allumage");
    pushNullTransition();
    state_9_subState = Allumage;
    NOTIFY_TRANSITION_STARTED("8");
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_9.Allumage.Acceleration");
    pushNullTransition();
    Allumage_subState = Acceleration;
    state_9_active = Acceleration;
    Allumage_timeout = scheduleTimeout(300, "ROOT.state_82.state_83.state_0.state_9.Allumage.Acceleration");
    NOTIFY_TRANSITION_TERMINATED("8");
}

IOxfReactive::TakeEventStatus _SysVehicule::Allumage_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMNullEventId))
        {
            //## transition 9 
            if(vContact==0 || vContact==1)
                {
                    NOTIFY_TRANSITION_STARTED("9");
                    popNullTransition();
                    switch (Allumage_subState) {
                        // State Acceleration
                        case Acceleration:
                        {
                            popNullTransition();
                            cancel(Allumage_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_9.Allumage.Acceleration");
                        }
                        break;
                        // State Freinage
                        case Freinage:
                        {
                            popNullTransition();
                            cancel(Allumage_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_9.Allumage.Freinage");
                        }
                        break;
                        default:
                            break;
                    }
                    Allumage_subState = OMNonState;
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_9.Allumage");
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_9.contact");
                    pushNullTransition();
                    state_9_subState = contact;
                    state_9_active = contact;
                    state_9_timeout = scheduleTimeout(200, "ROOT.state_82.state_83.state_0.state_9.contact");
                    NOTIFY_TRANSITION_TERMINATED("9");
                    res = eventConsumed;
                }
        }
    
    
    return res;
}

IOxfReactive::TakeEventStatus _SysVehicule::Freinage_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
        {
            if(getCurrentEvent() == Allumage_timeout)
                {
                    NOTIFY_TRANSITION_STARTED("4");
                    popNullTransition();
                    cancel(Allumage_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_9.Allumage.Freinage");
                    //#[ transition 4 
                    freiner(brakePedal);
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_9.Allumage.Freinage");
                    pushNullTransition();
                    Allumage_subState = Freinage;
                    state_9_active = Freinage;
                    Allumage_timeout = scheduleTimeout(200, "ROOT.state_82.state_83.state_0.state_9.Allumage.Freinage");
                    NOTIFY_TRANSITION_TERMINATED("4");
                    res = eventConsumed;
                }
        }
    else if(IS_EVENT_TYPE_OF(OMNullEventId))
        {
            //## transition 5 
            if(brakePedal==0)
                {
                    NOTIFY_TRANSITION_STARTED("5");
                    popNullTransition();
                    cancel(Allumage_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_9.Allumage.Freinage");
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_9.Allumage.Acceleration");
                    pushNullTransition();
                    Allumage_subState = Acceleration;
                    state_9_active = Acceleration;
                    Allumage_timeout = scheduleTimeout(300, "ROOT.state_82.state_83.state_0.state_9.Allumage.Acceleration");
                    NOTIFY_TRANSITION_TERMINATED("5");
                    res = eventConsumed;
                }
        }
    
    if(res == eventNotConsumed)
        {
            res = Allumage_handleEvent();
        }
    return res;
}

IOxfReactive::TakeEventStatus _SysVehicule::Acceleration_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
        {
            if(getCurrentEvent() == Allumage_timeout)
                {
                    NOTIFY_TRANSITION_STARTED("3");
                    popNullTransition();
                    cancel(Allumage_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_9.Allumage.Acceleration");
                    //#[ transition 3 
                    accelerer(accelPedal);
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_9.Allumage.Acceleration");
                    pushNullTransition();
                    Allumage_subState = Acceleration;
                    state_9_active = Acceleration;
                    Allumage_timeout = scheduleTimeout(300, "ROOT.state_82.state_83.state_0.state_9.Allumage.Acceleration");
                    NOTIFY_TRANSITION_TERMINATED("3");
                    res = eventConsumed;
                }
        }
    else if(IS_EVENT_TYPE_OF(OMNullEventId))
        {
            //## transition 6 
            if(brakePedal!=0)
                {
                    NOTIFY_TRANSITION_STARTED("6");
                    popNullTransition();
                    cancel(Allumage_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_9.Allumage.Acceleration");
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_9.Allumage.Freinage");
                    pushNullTransition();
                    Allumage_subState = Freinage;
                    state_9_active = Freinage;
                    Allumage_timeout = scheduleTimeout(200, "ROOT.state_82.state_83.state_0.state_9.Allumage.Freinage");
                    NOTIFY_TRANSITION_TERMINATED("6");
                    res = eventConsumed;
                }
        }
    
    if(res == eventNotConsumed)
        {
            res = Allumage_handleEvent();
        }
    return res;
}

void _SysVehicule::state_67_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_67");
    NOTIFY_TRANSITION_STARTED("38");
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_67.off");
    pushNullTransition();
    state_67_subState = off;
    state_67_active = off;
    NOTIFY_TRANSITION_TERMINATED("38");
}

void _SysVehicule::state_67_exit() {
    switch (state_67_subState) {
        // State off
        case off:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.off");
        }
        break;
        // State on
        case on:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.on");
        }
        break;
        // State jumele_car
        case jumele_car:
        {
            popNullTransition();
            cancel(state_67_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.jumele_car");
        }
        break;
        // State etat_sonne
        case etat_sonne:
        {
            cancel(state_67_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.etat_sonne");
        }
        break;
        // State appel
        case appel:
        {
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.appel");
        }
        break;
        // State state_97
        case state_97:
        {
            popNullTransition();
            cancel(state_67_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.state_97");
        }
        break;
        // State state_99
        case state_99:
        {
            popNullTransition();
            cancel(state_67_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.state_99");
        }
        break;
        default:
            break;
    }
    state_67_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67");
}

IOxfReactive::TakeEventStatus _SysVehicule::state_67_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (state_67_active) {
        // State off
        case off:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 39 
                    if(vContact==1 )
                        {
                            NOTIFY_TRANSITION_STARTED("39");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.off");
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_67.on");
                            pushNullTransition();
                            state_67_subState = on;
                            state_67_active = on;
                            NOTIFY_TRANSITION_TERMINATED("39");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        // State on
        case on:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 40 
                    if(vContact==0)
                        {
                            NOTIFY_TRANSITION_STARTED("40");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.on");
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_67.off");
                            pushNullTransition();
                            state_67_subState = off;
                            state_67_active = off;
                            NOTIFY_TRANSITION_TERMINATED("40");
                            res = eventConsumed;
                        }
                    else
                        {
                            //## transition 54 
                            if(IS_IN(jumele_tel))
                                {
                                    NOTIFY_TRANSITION_STARTED("54");
                                    popNullTransition();
                                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.on");
                                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_67.jumele_car");
                                    pushNullTransition();
                                    state_67_subState = jumele_car;
                                    state_67_active = jumele_car;
                                    state_67_timeout = scheduleTimeout(100, "ROOT.state_82.state_83.state_0.state_67.jumele_car");
                                    NOTIFY_TRANSITION_TERMINATED("54");
                                    res = eventConsumed;
                                }
                        }
                }
            
            
        }
        break;
        // State jumele_car
        case jumele_car:
        {
            res = jumele_car_handleEvent();
        }
        break;
        // State etat_sonne
        case etat_sonne:
        {
            res = etat_sonne_handleEvent();
        }
        break;
        // State appel
        case appel:
        {
            if(IS_EVENT_TYPE_OF(evAnnuleCar__MonPkg_id))
                {
                    NOTIFY_TRANSITION_STARTED("61");
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.appel");
                    //#[ transition 61 
                    appel_en_cours=false;
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_67.jumele_car");
                    pushNullTransition();
                    state_67_subState = jumele_car;
                    state_67_active = jumele_car;
                    state_67_timeout = scheduleTimeout(100, "ROOT.state_82.state_83.state_0.state_67.jumele_car");
                    NOTIFY_TRANSITION_TERMINATED("61");
                    res = eventConsumed;
                }
            
            
        }
        break;
        // State state_97
        case state_97:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == state_67_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("71");
                            popNullTransition();
                            cancel(state_67_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.state_97");
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_67.state_97");
                            pushNullTransition();
                            state_67_subState = state_97;
                            state_67_active = state_97;
                            state_67_timeout = scheduleTimeout(100, "ROOT.state_82.state_83.state_0.state_67.state_97");
                            NOTIFY_TRANSITION_TERMINATED("71");
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 70 
                    if(vContact==1)
                        {
                            NOTIFY_TRANSITION_STARTED("70");
                            popNullTransition();
                            cancel(state_67_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.state_97");
                            //#[ transition 70 
                            vJum=true;
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_67.jumele_car");
                            pushNullTransition();
                            state_67_subState = jumele_car;
                            state_67_active = jumele_car;
                            state_67_timeout = scheduleTimeout(100, "ROOT.state_82.state_83.state_0.state_67.jumele_car");
                            NOTIFY_TRANSITION_TERMINATED("70");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        // State state_99
        case state_99:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == state_67_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("77");
                            popNullTransition();
                            cancel(state_67_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.state_99");
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_67.state_99");
                            pushNullTransition();
                            state_67_subState = state_99;
                            state_67_active = state_99;
                            state_67_timeout = scheduleTimeout(100, "ROOT.state_82.state_83.state_0.state_67.state_99");
                            NOTIFY_TRANSITION_TERMINATED("77");
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 76 
                    if(IS_IN(state_94))
                        {
                            NOTIFY_TRANSITION_STARTED("76");
                            popNullTransition();
                            cancel(state_67_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.state_99");
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_67.jumele_car");
                            pushNullTransition();
                            state_67_subState = jumele_car;
                            state_67_active = jumele_car;
                            state_67_timeout = scheduleTimeout(100, "ROOT.state_82.state_83.state_0.state_67.jumele_car");
                            NOTIFY_TRANSITION_TERMINATED("76");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        default:
            break;
    }
    return res;
}

IOxfReactive::TakeEventStatus _SysVehicule::jumele_car_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
        {
            if(getCurrentEvent() == state_67_timeout)
                {
                    NOTIFY_TRANSITION_STARTED("79");
                    popNullTransition();
                    cancel(state_67_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.jumele_car");
                    //#[ transition 79 
                    vBatterie_tel=vBatterie;
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_67.jumele_car");
                    pushNullTransition();
                    state_67_subState = jumele_car;
                    state_67_active = jumele_car;
                    state_67_timeout = scheduleTimeout(100, "ROOT.state_82.state_83.state_0.state_67.jumele_car");
                    NOTIFY_TRANSITION_TERMINATED("79");
                    res = eventConsumed;
                }
        }
    else if(IS_EVENT_TYPE_OF(evSMS__MonPkg_id))
        {
            NOTIFY_TRANSITION_STARTED("62");
            popNullTransition();
            cancel(state_67_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.jumele_car");
            //#[ transition 62 
            cpt_sms+=1;
            //#]
            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_67.jumele_car");
            pushNullTransition();
            state_67_subState = jumele_car;
            state_67_active = jumele_car;
            state_67_timeout = scheduleTimeout(100, "ROOT.state_82.state_83.state_0.state_67.jumele_car");
            NOTIFY_TRANSITION_TERMINATED("62");
            res = eventConsumed;
        }
    else if(IS_EVENT_TYPE_OF(OMNullEventId))
        {
            //## transition 69 
            if(vContact==0)
                {
                    NOTIFY_TRANSITION_STARTED("69");
                    popNullTransition();
                    cancel(state_67_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.jumele_car");
                    //#[ transition 69 
                    vJum=false;
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_67.state_97");
                    pushNullTransition();
                    state_67_subState = state_97;
                    state_67_active = state_97;
                    state_67_timeout = scheduleTimeout(100, "ROOT.state_82.state_83.state_0.state_67.state_97");
                    NOTIFY_TRANSITION_TERMINATED("69");
                    res = eventConsumed;
                }
            else
                {
                    //## transition 75 
                    if(IS_IN(no_battery))
                        {
                            NOTIFY_TRANSITION_STARTED("75");
                            popNullTransition();
                            cancel(state_67_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.jumele_car");
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_67.state_99");
                            pushNullTransition();
                            state_67_subState = state_99;
                            state_67_active = state_99;
                            state_67_timeout = scheduleTimeout(100, "ROOT.state_82.state_83.state_0.state_67.state_99");
                            NOTIFY_TRANSITION_TERMINATED("75");
                            res = eventConsumed;
                        }
                }
        }
    else if(IS_EVENT_TYPE_OF(evAppel__MonPkg_id))
        {
            NOTIFY_TRANSITION_STARTED("57");
            popNullTransition();
            cancel(state_67_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.jumele_car");
            //#[ transition 57 
            PlaySound(TEXT("sonnerie.wav"), NULL, SND_LOOP | SND_ASYNC);
            //#]
            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_67.etat_sonne");
            state_67_subState = etat_sonne;
            state_67_active = etat_sonne;
            state_67_timeout = scheduleTimeout(100, "ROOT.state_82.state_83.state_0.state_67.etat_sonne");
            NOTIFY_TRANSITION_TERMINATED("57");
            res = eventConsumed;
        }
    
    
    return res;
}

IOxfReactive::TakeEventStatus _SysVehicule::etat_sonne_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
        {
            if(getCurrentEvent() == state_67_timeout)
                {
                    NOTIFY_TRANSITION_STARTED("58");
                    cancel(state_67_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.etat_sonne");
                    //#[ transition 58 
                    vSonnerie=!vSonnerie;
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_67.etat_sonne");
                    state_67_subState = etat_sonne;
                    state_67_active = etat_sonne;
                    state_67_timeout = scheduleTimeout(100, "ROOT.state_82.state_83.state_0.state_67.etat_sonne");
                    NOTIFY_TRANSITION_TERMINATED("58");
                    res = eventConsumed;
                }
        }
    else if(IS_EVENT_TYPE_OF(evOkCar__MonPkg_id))
        {
            NOTIFY_TRANSITION_STARTED("59");
            cancel(state_67_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.etat_sonne");
            //#[ transition 59 
            PlaySound(NULL, 0, 0);
            appel_en_cours=true;
            //#]
            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_67.appel");
            state_67_subState = appel;
            state_67_active = appel;
            NOTIFY_TRANSITION_TERMINATED("59");
            res = eventConsumed;
        }
    else if(IS_EVENT_TYPE_OF(evAnnuleCar__MonPkg_id))
        {
            NOTIFY_TRANSITION_STARTED("60");
            cancel(state_67_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_67.etat_sonne");
            //#[ transition 60 
            PlaySound(NULL, 0, 0);
            //#]
            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_67.jumele_car");
            pushNullTransition();
            state_67_subState = jumele_car;
            state_67_active = jumele_car;
            state_67_timeout = scheduleTimeout(100, "ROOT.state_82.state_83.state_0.state_67.jumele_car");
            NOTIFY_TRANSITION_TERMINATED("60");
            res = eventConsumed;
        }
    
    
    return res;
}

void _SysVehicule::state_49_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_49");
    NOTIFY_TRANSITION_STARTED("30");
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_49.state_50");
    pushNullTransition();
    state_49_subState = state_50;
    state_49_active = state_50;
    NOTIFY_TRANSITION_TERMINATED("30");
}

void _SysVehicule::state_49_exit() {
    switch (state_49_subState) {
        // State state_50
        case state_50:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_49.state_50");
        }
        break;
        // State state_51
        case state_51:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_49.state_51");
        }
        break;
        // State state_52
        case state_52:
        {
            cancel(state_49_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_49.state_52");
        }
        break;
        // State state_60
        case state_60:
        {
            cancel(state_49_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_49.state_60");
        }
        break;
        default:
            break;
    }
    state_49_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_49");
}

IOxfReactive::TakeEventStatus _SysVehicule::state_49_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (state_49_active) {
        // State state_50
        case state_50:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 31 
                    if(IS_IN(Limitation))
                        {
                            NOTIFY_TRANSITION_STARTED("31");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_49.state_50");
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_49.state_51");
                            pushNullTransition();
                            state_49_subState = state_51;
                            state_49_active = state_51;
                            NOTIFY_TRANSITION_TERMINATED("31");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        // State state_51
        case state_51:
        {
            res = state_51_handleEvent();
        }
        break;
        // State state_52
        case state_52:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == state_49_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("25");
                            cancel(state_49_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_49.state_52");
                            //#[ transition 25 
                            vitesseConsigne+=1;
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_49.state_51");
                            pushNullTransition();
                            state_49_subState = state_51;
                            state_49_active = state_51;
                            NOTIFY_TRANSITION_TERMINATED("25");
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(evPush__MonPkg_id))
                {
                    NOTIFY_TRANSITION_STARTED("26");
                    cancel(state_49_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_49.state_52");
                    //#[ transition 26 
                    vitesseConsigne+=10;
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_49.state_51");
                    pushNullTransition();
                    state_49_subState = state_51;
                    state_49_active = state_51;
                    NOTIFY_TRANSITION_TERMINATED("26");
                    res = eventConsumed;
                }
            
            
        }
        break;
        // State state_60
        case state_60:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == state_49_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("29");
                            cancel(state_49_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_49.state_60");
                            //#[ transition 29 
                            vitesseConsigne-=1;
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_49.state_51");
                            pushNullTransition();
                            state_49_subState = state_51;
                            state_49_active = state_51;
                            NOTIFY_TRANSITION_TERMINATED("29");
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(evPushM__MonPkg_id))
                {
                    NOTIFY_TRANSITION_STARTED("28");
                    cancel(state_49_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_49.state_60");
                    //#[ transition 28 
                    vitesseConsigne-=10;
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_49.state_51");
                    pushNullTransition();
                    state_49_subState = state_51;
                    state_49_active = state_51;
                    NOTIFY_TRANSITION_TERMINATED("28");
                    res = eventConsumed;
                }
            
            
        }
        break;
        default:
            break;
    }
    return res;
}

IOxfReactive::TakeEventStatus _SysVehicule::state_51_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(evPushM__MonPkg_id))
        {
            NOTIFY_TRANSITION_STARTED("27");
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_49.state_51");
            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_49.state_60");
            state_49_subState = state_60;
            state_49_active = state_60;
            state_49_timeout = scheduleTimeout(500, "ROOT.state_82.state_83.state_0.state_49.state_60");
            NOTIFY_TRANSITION_TERMINATED("27");
            res = eventConsumed;
        }
    else if(IS_EVENT_TYPE_OF(OMNullEventId))
        {
            //## transition 80 
            if(IS_IN(state_47))
                {
                    NOTIFY_TRANSITION_STARTED("80");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_49.state_51");
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_49.state_50");
                    pushNullTransition();
                    state_49_subState = state_50;
                    state_49_active = state_50;
                    NOTIFY_TRANSITION_TERMINATED("80");
                    res = eventConsumed;
                }
        }
    else if(IS_EVENT_TYPE_OF(evPush__MonPkg_id))
        {
            NOTIFY_TRANSITION_STARTED("24");
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_49.state_51");
            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_49.state_52");
            state_49_subState = state_52;
            state_49_active = state_52;
            state_49_timeout = scheduleTimeout(500, "ROOT.state_82.state_83.state_0.state_49.state_52");
            NOTIFY_TRANSITION_TERMINATED("24");
            res = eventConsumed;
        }
    
    
    return res;
}

void _SysVehicule::state_32_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_32");
    NOTIFY_TRANSITION_STARTED("37");
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_32.state_47");
    pushNullTransition();
    state_32_subState = state_47;
    state_32_active = state_47;
    NOTIFY_TRANSITION_TERMINATED("37");
}

void _SysVehicule::state_32_exit() {
    switch (state_32_subState) {
        // State state_47
        case state_47:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_32.state_47");
        }
        break;
        // State Limitation
        case Limitation:
        {
            popNullTransition();
            cancel(state_32_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_32.Limitation");
        }
        break;
        // State state_62
        case state_62:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_32.state_62");
        }
        break;
        // State state_63
        case state_63:
        {
            cancel(state_32_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_32.state_63");
        }
        break;
        default:
            break;
    }
    state_32_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_32");
}

IOxfReactive::TakeEventStatus _SysVehicule::state_32_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (state_32_active) {
        // State state_47
        case state_47:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 21 
                    if(IS_IN(state_23)&&limiteur&&speed==vitesseLimite)
                        {
                            NOTIFY_TRANSITION_STARTED("21");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_32.state_47");
                            //#[ transition 21 
                            vitesseConsigne=vitesseLimite;
                            MemoryAccel=accelPedal;
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_32.Limitation");
                            pushNullTransition();
                            state_32_subState = Limitation;
                            state_32_active = Limitation;
                            state_32_timeout = scheduleTimeout(50, "ROOT.state_82.state_83.state_0.state_32.Limitation");
                            NOTIFY_TRANSITION_TERMINATED("21");
                            res = eventConsumed;
                        }
                    else
                        {
                            //## transition 33 
                            if(IS_IN(state_23)&&limiteur&&speed>vitesseLimite)
                                {
                                    NOTIFY_TRANSITION_STARTED("33");
                                    popNullTransition();
                                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_32.state_47");
                                    //#[ transition 33 
                                    vitesseConsigne=vitesseLimite;
                                    LED=true;
                                    //#]
                                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_32.state_62");
                                    pushNullTransition();
                                    state_32_subState = state_62;
                                    state_32_active = state_62;
                                    NOTIFY_TRANSITION_TERMINATED("33");
                                    res = eventConsumed;
                                }
                        }
                }
            
            
        }
        break;
        // State Limitation
        case Limitation:
        {
            res = Limitation_handleEvent();
        }
        break;
        // State state_62
        case state_62:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 34 
                    if(speed<=vitesseConsigne)
                        {
                            NOTIFY_TRANSITION_STARTED("34");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_32.state_62");
                            //#[ transition 34 
                            LED=false;
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_32.Limitation");
                            pushNullTransition();
                            state_32_subState = Limitation;
                            state_32_active = Limitation;
                            state_32_timeout = scheduleTimeout(50, "ROOT.state_82.state_83.state_0.state_32.Limitation");
                            NOTIFY_TRANSITION_TERMINATED("34");
                            res = eventConsumed;
                        }
                    else
                        {
                            //## transition 78 
                            if(alpha>10||alpha<-10)
                                {
                                    NOTIFY_TRANSITION_STARTED("78");
                                    popNullTransition();
                                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_32.state_62");
                                    //#[ transition 78 
                                    limiteur=false;
                                    PlaySound(TEXT("bip.wav"), NULL, SND_LOOP | SND_ASYNC);
                                    LED=false;
                                    //#]
                                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_32.state_63");
                                    state_32_subState = state_63;
                                    state_32_active = state_63;
                                    state_32_timeout = scheduleTimeout(5000, "ROOT.state_82.state_83.state_0.state_32.state_63");
                                    NOTIFY_TRANSITION_TERMINATED("78");
                                    res = eventConsumed;
                                }
                        }
                }
            
            
        }
        break;
        // State state_63
        case state_63:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == state_32_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("35");
                            cancel(state_32_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_32.state_63");
                            //#[ transition 35 
                            PlaySound(NULL, 0, 0);
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_32.state_47");
                            pushNullTransition();
                            state_32_subState = state_47;
                            state_32_active = state_47;
                            NOTIFY_TRANSITION_TERMINATED("35");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        default:
            break;
    }
    return res;
}

IOxfReactive::TakeEventStatus _SysVehicule::Limitation_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
        {
            if(getCurrentEvent() == state_32_timeout)
                {
                    NOTIFY_TRANSITION_STARTED("23");
                    popNullTransition();
                    cancel(state_32_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_32.Limitation");
                    //#[ transition 23 
                    regulation();
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_32.Limitation");
                    pushNullTransition();
                    state_32_subState = Limitation;
                    state_32_active = Limitation;
                    state_32_timeout = scheduleTimeout(50, "ROOT.state_82.state_83.state_0.state_32.Limitation");
                    NOTIFY_TRANSITION_TERMINATED("23");
                    res = eventConsumed;
                }
        }
    else if(IS_EVENT_TYPE_OF(OMNullEventId))
        {
            //## transition 22 
            if(!limiteur||(accelPedal>6))
                {
                    NOTIFY_TRANSITION_STARTED("22");
                    popNullTransition();
                    cancel(state_32_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_32.Limitation");
                    //#[ transition 22 
                    limiteur=false;
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_32.state_47");
                    pushNullTransition();
                    state_32_subState = state_47;
                    state_32_active = state_47;
                    NOTIFY_TRANSITION_TERMINATED("22");
                    res = eventConsumed;
                }
            else
                {
                    //## transition 32 
                    if(alpha>10||alpha<-10)
                        {
                            NOTIFY_TRANSITION_STARTED("32");
                            popNullTransition();
                            cancel(state_32_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_32.Limitation");
                            //#[ transition 32 
                            limiteur=false;
                            PlaySound(TEXT("bip.wav"), NULL, SND_LOOP | SND_ASYNC);
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_32.state_63");
                            state_32_subState = state_63;
                            state_32_active = state_63;
                            state_32_timeout = scheduleTimeout(5000, "ROOT.state_82.state_83.state_0.state_32.state_63");
                            NOTIFY_TRANSITION_TERMINATED("32");
                            res = eventConsumed;
                        }
                    else
                        {
                            //## transition 81 
                            if(brakePedal!=0)
                                {
                                    NOTIFY_TRANSITION_STARTED("81");
                                    popNullTransition();
                                    cancel(state_32_timeout);
                                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_32.Limitation");
                                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_32.state_47");
                                    pushNullTransition();
                                    state_32_subState = state_47;
                                    state_32_active = state_47;
                                    NOTIFY_TRANSITION_TERMINATED("81");
                                    res = eventConsumed;
                                }
                        }
                }
        }
    
    
    return res;
}

void _SysVehicule::state_2_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_2");
    NOTIFY_TRANSITION_STARTED("7");
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_2.state_13");
    state_2_subState = state_13;
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_2.state_13.state_13");
    state_13_subState = state_13_state_13;
    state_2_active = state_13_state_13;
    state_13_timeout = scheduleTimeout(50, "ROOT.state_82.state_83.state_0.state_2.state_13.state_13");
    NOTIFY_TRANSITION_TERMINATED("7");
}

void _SysVehicule::state_2_exit() {
    // State state_13
    if(state_2_subState == state_13)
        {
            state_13_exit();
        }
    state_2_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_2");
}

IOxfReactive::TakeEventStatus _SysVehicule::state_2_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    // State state_13
    if(state_2_active == state_13_state_13)
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == state_13_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("2");
                            cancel(state_13_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_2.state_13.state_13");
                            //#[ transition 2 
                            calcul_vitesse_distance(throttle);
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_2.state_13.state_13");
                            state_13_subState = state_13_state_13;
                            state_2_active = state_13_state_13;
                            state_13_timeout = scheduleTimeout(50, "ROOT.state_82.state_83.state_0.state_2.state_13.state_13");
                            NOTIFY_TRANSITION_TERMINATED("2");
                            res = eventConsumed;
                        }
                }
            
            
        }
    return res;
}

void _SysVehicule::state_13_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_2.state_13");
    state_2_subState = state_13;
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_2.state_13.state_13");
    state_13_subState = state_13_state_13;
    state_2_active = state_13_state_13;
    state_13_timeout = scheduleTimeout(50, "ROOT.state_82.state_83.state_0.state_2.state_13.state_13");
}

void _SysVehicule::state_13_exit() {
    // State state_13
    if(state_13_subState == state_13_state_13)
        {
            cancel(state_13_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_2.state_13.state_13");
        }
    state_13_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_2.state_13");
}

void _SysVehicule::state_1_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_1");
    NOTIFY_TRANSITION_STARTED("36");
    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_1.state_23");
    pushNullTransition();
    state_1_subState = state_23;
    state_1_active = state_23;
    NOTIFY_TRANSITION_TERMINATED("36");
}

IOxfReactive::TakeEventStatus _SysVehicule::state_1_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (state_1_active) {
        // State state_23
        case state_23:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 13 
                    if(IS_IN(state_47)&&regulateur && speed>50)
                        {
                            NOTIFY_TRANSITION_STARTED("13");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_1.state_23");
                            //#[ transition 13 
                            vitesseConsigne=speed;
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_1.state_24");
                            pushNullTransition();
                            state_1_subState = state_24;
                            state_1_active = state_24;
                            state_1_timeout = scheduleTimeout(50, "ROOT.state_82.state_83.state_0.state_1.state_24");
                            NOTIFY_TRANSITION_TERMINATED("13");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        // State state_24
        case state_24:
        {
            res = state_24_handleEvent();
        }
        break;
        // State state_31
        case state_31:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == state_1_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("20");
                            popNullTransition();
                            cancel(state_1_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_1.state_31");
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_1.state_31");
                            pushNullTransition();
                            state_1_subState = state_31;
                            state_1_active = state_31;
                            state_1_timeout = scheduleTimeout(50, "ROOT.state_82.state_83.state_0.state_1.state_31");
                            NOTIFY_TRANSITION_TERMINATED("20");
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 19 
                    if(accelPedal==0)
                        {
                            NOTIFY_TRANSITION_STARTED("19");
                            popNullTransition();
                            cancel(state_1_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_1.state_31");
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_1.state_24");
                            pushNullTransition();
                            state_1_subState = state_24;
                            state_1_active = state_24;
                            state_1_timeout = scheduleTimeout(50, "ROOT.state_82.state_83.state_0.state_1.state_24");
                            NOTIFY_TRANSITION_TERMINATED("19");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        default:
            break;
    }
    return res;
}

IOxfReactive::TakeEventStatus _SysVehicule::state_24_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(evPushM__MonPkg_id))
        {
            NOTIFY_TRANSITION_STARTED("17");
            popNullTransition();
            cancel(state_1_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_1.state_24");
            //#[ transition 17 
            vitesseConsigne-=1;
            //#]
            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_1.state_24");
            pushNullTransition();
            state_1_subState = state_24;
            state_1_active = state_24;
            state_1_timeout = scheduleTimeout(50, "ROOT.state_82.state_83.state_0.state_1.state_24");
            NOTIFY_TRANSITION_TERMINATED("17");
            res = eventConsumed;
        }
    else if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
        {
            if(getCurrentEvent() == state_1_timeout)
                {
                    NOTIFY_TRANSITION_STARTED("15");
                    popNullTransition();
                    cancel(state_1_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_1.state_24");
                    //#[ transition 15 
                    regulation();
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_1.state_24");
                    pushNullTransition();
                    state_1_subState = state_24;
                    state_1_active = state_24;
                    state_1_timeout = scheduleTimeout(50, "ROOT.state_82.state_83.state_0.state_1.state_24");
                    NOTIFY_TRANSITION_TERMINATED("15");
                    res = eventConsumed;
                }
        }
    else if(IS_EVENT_TYPE_OF(OMNullEventId))
        {
            //## transition 14 
            if(!regulateur||brakePedal!=0||speed<50)
                {
                    NOTIFY_TRANSITION_STARTED("14");
                    popNullTransition();
                    cancel(state_1_timeout);
                    NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_1.state_24");
                    //#[ transition 14 
                    regulateur=false;
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_1.state_23");
                    pushNullTransition();
                    state_1_subState = state_23;
                    state_1_active = state_23;
                    NOTIFY_TRANSITION_TERMINATED("14");
                    res = eventConsumed;
                }
            else
                {
                    //## transition 18 
                    if(accelPedal!=0)
                        {
                            NOTIFY_TRANSITION_STARTED("18");
                            popNullTransition();
                            cancel(state_1_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_1.state_24");
                            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_1.state_31");
                            pushNullTransition();
                            state_1_subState = state_31;
                            state_1_active = state_31;
                            state_1_timeout = scheduleTimeout(50, "ROOT.state_82.state_83.state_0.state_1.state_31");
                            NOTIFY_TRANSITION_TERMINATED("18");
                            res = eventConsumed;
                        }
                }
        }
    else if(IS_EVENT_TYPE_OF(evPush__MonPkg_id))
        {
            NOTIFY_TRANSITION_STARTED("16");
            popNullTransition();
            cancel(state_1_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_82.state_83.state_0.state_1.state_24");
            //#[ transition 16 
            vitesseConsigne+=1;
            //#]
            NOTIFY_STATE_ENTERED("ROOT.state_82.state_83.state_0.state_1.state_24");
            pushNullTransition();
            state_1_subState = state_24;
            state_1_active = state_24;
            state_1_timeout = scheduleTimeout(50, "ROOT.state_82.state_83.state_0.state_1.state_24");
            NOTIFY_TRANSITION_TERMINATED("16");
            res = eventConsumed;
        }
    
    
    return res;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimated_SysVehicule::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("fspeed", x2String(myReal->fspeed));
    aomsAttributes->addAttribute("fdist", x2String(myReal->fdist));
    aomsAttributes->addAttribute("airResistance", x2String(myReal->airResistance));
    aomsAttributes->addAttribute("speed", x2String(myReal->speed));
    aomsAttributes->addAttribute("brakePedal", x2String(myReal->brakePedal));
    aomsAttributes->addAttribute("ignition", x2String(myReal->ignition));
    aomsAttributes->addAttribute("MAX_SPEED", x2String(myReal->MAX_SPEED));
    aomsAttributes->addAttribute("MAX_BRAKE", x2String(myReal->MAX_BRAKE));
    aomsAttributes->addAttribute("MAX_THROTTLE", x2String(myReal->MAX_THROTTLE));
    aomsAttributes->addAttribute("distance", x2String(myReal->distance));
    aomsAttributes->addAttribute("throttle", x2String(myReal->throttle));
    aomsAttributes->addAttribute("alpha", x2String(myReal->alpha));
    aomsAttributes->addAttribute("accelPedal", x2String(myReal->accelPedal));
    aomsAttributes->addAttribute("error", x2String(myReal->error));
    aomsAttributes->addAttribute("steady", x2String(myReal->steady));
    aomsAttributes->addAttribute("_simu", x2String(myReal->_simu));
    aomsAttributes->addAttribute("vitesseConsigne", x2String(myReal->vitesseConsigne));
    aomsAttributes->addAttribute("regulateur", x2String(myReal->regulateur));
    aomsAttributes->addAttribute("limiteur", x2String(myReal->limiteur));
    aomsAttributes->addAttribute("vitesseLimite", x2String(myReal->vitesseLimite));
    aomsAttributes->addAttribute("diminution_int_0", x2String(myReal->diminution_int_0));
    aomsAttributes->addAttribute("augmentation_int_0", x2String(myReal->augmentation_int_0));
    aomsAttributes->addAttribute("MemoryAccel", x2String(myReal->MemoryAccel));
    aomsAttributes->addAttribute("Alarme", x2String(myReal->Alarme));
    aomsAttributes->addAttribute("LED", x2String(myReal->LED));
    aomsAttributes->addAttribute("Voyant", x2String(myReal->Voyant));
    aomsAttributes->addAttribute("vContact", x2String(myReal->vContact));
    aomsAttributes->addAttribute("bluetooth", x2String(myReal->bluetooth));
    aomsAttributes->addAttribute("affiche_kit_b_car", x2String(myReal->affiche_kit_b_car));
    aomsAttributes->addAttribute("bouton_tel", x2String(myReal->bouton_tel));
    aomsAttributes->addAttribute("vJum", x2String(myReal->vJum));
    aomsAttributes->addAttribute("vSonnerie", x2String(myReal->vSonnerie));
    aomsAttributes->addAttribute("cpt_sms", x2String(myReal->cpt_sms));
    aomsAttributes->addAttribute("vSonnerieTel", x2String(myReal->vSonnerieTel));
    aomsAttributes->addAttribute("vBatterie", x2String(myReal->vBatterie));
    aomsAttributes->addAttribute("vBatterie_tel", x2String(myReal->vBatterie_tel));
    aomsAttributes->addAttribute("appel_en_cours", x2String(myReal->appel_en_cours));
}

void OMAnimated_SysVehicule::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    if(myReal->rootState_subState == _SysVehicule::state_82)
        {
            state_82_serializeStates(aomsState);
        }
}

void OMAnimated_SysVehicule::state_82_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82");
    state_83_serializeStates(aomsState);
    state_84_serializeStates(aomsState);
}

void OMAnimated_SysVehicule::state_84_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_84");
    if(myReal->state_84_subState == _SysVehicule::Telephone)
        {
            Telephone_serializeStates(aomsState);
        }
}

void OMAnimated_SysVehicule::Telephone_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_84.Telephone");
    state_89_serializeStates(aomsState);
    state_90_serializeStates(aomsState);
}

void OMAnimated_SysVehicule::state_90_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_84.Telephone.state_90");
    switch (myReal->state_90_subState) {
        case _SysVehicule::state_94:
        {
            state_94_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_95:
        {
            state_95_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_96:
        {
            state_96_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::no_battery:
        {
            no_battery_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimated_SysVehicule::state_96_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_84.Telephone.state_90.state_96");
}

void OMAnimated_SysVehicule::state_95_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_84.Telephone.state_90.state_95");
}

void OMAnimated_SysVehicule::state_94_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_84.Telephone.state_90.state_94");
}

void OMAnimated_SysVehicule::no_battery_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_84.Telephone.state_90.no_battery");
}

void OMAnimated_SysVehicule::state_89_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_84.Telephone.state_89");
    switch (myReal->state_89_subState) {
        case _SysVehicule::state_73:
        {
            state_73_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_74:
        {
            state_74_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_75:
        {
            state_75_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::jumelage:
        {
            jumelage_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_77:
        {
            state_77_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_78:
        {
            state_78_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_79:
        {
            state_79_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::jumele_tel:
        {
            jumele_tel_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimated_SysVehicule::state_79_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_84.Telephone.state_89.state_79");
}

void OMAnimated_SysVehicule::state_78_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_84.Telephone.state_89.state_78");
}

void OMAnimated_SysVehicule::state_77_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_84.Telephone.state_89.state_77");
}

void OMAnimated_SysVehicule::state_75_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_84.Telephone.state_89.state_75");
}

void OMAnimated_SysVehicule::state_74_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_84.Telephone.state_89.state_74");
}

void OMAnimated_SysVehicule::state_73_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_84.Telephone.state_89.state_73");
}

void OMAnimated_SysVehicule::jumele_tel_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_84.Telephone.state_89.jumele_tel");
}

void OMAnimated_SysVehicule::jumelage_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_84.Telephone.state_89.jumelage");
}

void OMAnimated_SysVehicule::state_83_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83");
    switch (myReal->state_83_subState) {
        case _SysVehicule::state_0:
        {
            state_0_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_4:
        {
            state_4_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimated_SysVehicule::state_4_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_4");
}

void OMAnimated_SysVehicule::state_0_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0");
    state_1_serializeStates(aomsState);
    state_2_serializeStates(aomsState);
    state_9_serializeStates(aomsState);
    state_32_serializeStates(aomsState);
    state_49_serializeStates(aomsState);
    state_67_serializeStates(aomsState);
}

void OMAnimated_SysVehicule::state_9_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_9");
    switch (myReal->state_9_subState) {
        case _SysVehicule::Allumage:
        {
            Allumage_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::contact:
        {
            contact_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimated_SysVehicule::contact_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_9.contact");
}

void OMAnimated_SysVehicule::Allumage_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_9.Allumage");
    switch (myReal->Allumage_subState) {
        case _SysVehicule::Acceleration:
        {
            Acceleration_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::Freinage:
        {
            Freinage_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimated_SysVehicule::Freinage_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_9.Allumage.Freinage");
}

void OMAnimated_SysVehicule::Acceleration_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_9.Allumage.Acceleration");
}

void OMAnimated_SysVehicule::state_67_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_67");
    switch (myReal->state_67_subState) {
        case _SysVehicule::off:
        {
            off_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::on:
        {
            on_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::jumele_car:
        {
            jumele_car_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::etat_sonne:
        {
            etat_sonne_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::appel:
        {
            appel_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_97:
        {
            state_97_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_99:
        {
            state_99_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimated_SysVehicule::state_99_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_67.state_99");
}

void OMAnimated_SysVehicule::state_97_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_67.state_97");
}

void OMAnimated_SysVehicule::on_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_67.on");
}

void OMAnimated_SysVehicule::off_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_67.off");
}

void OMAnimated_SysVehicule::jumele_car_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_67.jumele_car");
}

void OMAnimated_SysVehicule::etat_sonne_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_67.etat_sonne");
}

void OMAnimated_SysVehicule::appel_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_67.appel");
}

void OMAnimated_SysVehicule::state_49_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_49");
    switch (myReal->state_49_subState) {
        case _SysVehicule::state_50:
        {
            state_50_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_51:
        {
            state_51_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_52:
        {
            state_52_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_60:
        {
            state_60_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimated_SysVehicule::state_60_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_49.state_60");
}

void OMAnimated_SysVehicule::state_52_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_49.state_52");
}

void OMAnimated_SysVehicule::state_51_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_49.state_51");
}

void OMAnimated_SysVehicule::state_50_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_49.state_50");
}

void OMAnimated_SysVehicule::state_32_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_32");
    switch (myReal->state_32_subState) {
        case _SysVehicule::state_47:
        {
            state_47_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::Limitation:
        {
            Limitation_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_62:
        {
            state_62_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_63:
        {
            state_63_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimated_SysVehicule::state_63_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_32.state_63");
}

void OMAnimated_SysVehicule::state_62_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_32.state_62");
}

void OMAnimated_SysVehicule::state_47_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_32.state_47");
}

void OMAnimated_SysVehicule::Limitation_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_32.Limitation");
}

void OMAnimated_SysVehicule::state_2_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_2");
    if(myReal->state_2_subState == _SysVehicule::state_13)
        {
            state_13_serializeStates(aomsState);
        }
}

void OMAnimated_SysVehicule::state_13_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_2.state_13");
    if(myReal->state_13_subState == _SysVehicule::state_13_state_13)
        {
            state_13_state_13_serializeStates(aomsState);
        }
}

void OMAnimated_SysVehicule::state_13_state_13_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_2.state_13.state_13");
}

void OMAnimated_SysVehicule::state_1_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_1");
    switch (myReal->state_1_subState) {
        case _SysVehicule::state_23:
        {
            state_23_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_24:
        {
            state_24_serializeStates(aomsState);
        }
        break;
        case _SysVehicule::state_31:
        {
            state_31_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimated_SysVehicule::state_31_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_1.state_31");
}

void OMAnimated_SysVehicule::state_24_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_1.state_24");
}

void OMAnimated_SysVehicule::state_23_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_82.state_83.state_0.state_1.state_23");
}
//#]

IMPLEMENT_REACTIVE_META_P(_SysVehicule, _MonPkg, _MonPkg, false, OMAnimated_SysVehicule)

IMPLEMENT_META_OP(OMAnimated_SysVehicule, _MonPkg__SysVehicule_setAccelPedal_double, "setAccelPedal", FALSE, "setAccelPedal(double)", 1)

IMPLEMENT_OP_CALL(_MonPkg__SysVehicule_setAccelPedal_double, _SysVehicule, setAccelPedal(p_accelPedal), NO_OP())

IMPLEMENT_META_OP(OMAnimated_SysVehicule, _MonPkg__SysVehicule_setAlpha_int, "setAlpha", FALSE, "setAlpha(int)", 1)

IMPLEMENT_OP_CALL(_MonPkg__SysVehicule_setAlpha_int, _SysVehicule, setAlpha(p_alpha), NO_OP())

IMPLEMENT_META_OP(OMAnimated_SysVehicule, _MonPkg__SysVehicule_setBluetooth_bool, "setBluetooth", FALSE, "setBluetooth(bool)", 1)

IMPLEMENT_OP_CALL(_MonPkg__SysVehicule_setBluetooth_bool, _SysVehicule, setBluetooth(p_bluetooth), NO_OP())

IMPLEMENT_META_OP(OMAnimated_SysVehicule, _MonPkg__SysVehicule_setBouton_tel_int, "setBouton_tel", FALSE, "setBouton_tel(int)", 1)

IMPLEMENT_OP_CALL(_MonPkg__SysVehicule_setBouton_tel_int, _SysVehicule, setBouton_tel(p_bouton_tel), NO_OP())

IMPLEMENT_META_OP(OMAnimated_SysVehicule, _MonPkg__SysVehicule_setBrakePedal_double, "setBrakePedal", FALSE, "setBrakePedal(double)", 1)

IMPLEMENT_OP_CALL(_MonPkg__SysVehicule_setBrakePedal_double, _SysVehicule, setBrakePedal(p_brakePedal), NO_OP())

IMPLEMENT_META_OP(OMAnimated_SysVehicule, _MonPkg__SysVehicule_setLimiteur_bool, "setLimiteur", FALSE, "setLimiteur(bool)", 1)

IMPLEMENT_OP_CALL(_MonPkg__SysVehicule_setLimiteur_bool, _SysVehicule, setLimiteur(p_limiteur), NO_OP())

IMPLEMENT_META_OP(OMAnimated_SysVehicule, _MonPkg__SysVehicule_setRegulateur_bool, "setRegulateur", FALSE, "setRegulateur(bool)", 1)

IMPLEMENT_OP_CALL(_MonPkg__SysVehicule_setRegulateur_bool, _SysVehicule, setRegulateur(p_regulateur), NO_OP())

IMPLEMENT_META_OP(OMAnimated_SysVehicule, _MonPkg__SysVehicule_setVContact_int, "setVContact", FALSE, "setVContact(int)", 1)

IMPLEMENT_OP_CALL(_MonPkg__SysVehicule_setVContact_int, _SysVehicule, setVContact(p_vContact), NO_OP())

IMPLEMENT_META_OP(OMAnimated_SysVehicule, _MonPkg__SysVehicule_setVitesseLimite_int, "setVitesseLimite", FALSE, "setVitesseLimite(int)", 1)

IMPLEMENT_OP_CALL(_MonPkg__SysVehicule_setVitesseLimite_int, _SysVehicule, setVitesseLimite(p_vitesseLimite), NO_OP())
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: CodesGeneres\ModeAnimation\_SysVehicule.cpp
*********************************************************************/
