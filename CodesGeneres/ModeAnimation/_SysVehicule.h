/*********************************************************************
	Rhapsody	: 9.0 
	Login		: mikae
	Component	: CodesGeneres 
	Configuration 	: ModeAnimation
	Model Element	: _SysVehicule
//!	Generated Date	: Sat, 12, Nov 2022  
	File Path	: CodesGeneres\ModeAnimation\_SysVehicule.h
*********************************************************************/

#ifndef _SysVehicule_H
#define _SysVehicule_H

//## dependency math
#include <math.h>
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
#include "_MonPkg.h"
//## auto_generated
#include <oxf\omthread.h>
//## auto_generated
#include <oxf\omreactive.h>
//## auto_generated
#include <oxf\state.h>
//## auto_generated
#include <oxf\event.h>
//#[ ignore
#define OMAnim__MonPkg__SysVehicule_setAccelPedal_double_ARGS_DECLARATION double p_accelPedal;

#define OMAnim__MonPkg__SysVehicule_setAlpha_int_ARGS_DECLARATION int p_alpha;

#define OMAnim__MonPkg__SysVehicule_setBluetooth_bool_ARGS_DECLARATION bool p_bluetooth;

#define OMAnim__MonPkg__SysVehicule_setBouton_tel_int_ARGS_DECLARATION int p_bouton_tel;

#define OMAnim__MonPkg__SysVehicule_setBrakePedal_double_ARGS_DECLARATION double p_brakePedal;

#define OMAnim__MonPkg__SysVehicule_setLimiteur_bool_ARGS_DECLARATION bool p_limiteur;

#define OMAnim__MonPkg__SysVehicule_setRegulateur_bool_ARGS_DECLARATION bool p_regulateur;

#define OMAnim__MonPkg__SysVehicule_setVContact_int_ARGS_DECLARATION int p_vContact;

#define OMAnim__MonPkg__SysVehicule_setVitesseLimite_int_ARGS_DECLARATION int p_vitesseLimite;
//#]

//## package _MonPkg

//## class _SysVehicule
class _SysVehicule : public OMThread, public OMReactive {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimated_SysVehicule;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    ////    Operations    ////
    
    //## operation accelerer(double)
    double accelerer(double accelPedal);
    
    //## operation calcul_vitesse_distance(double)
    void calcul_vitesse_distance(double& throttle);
    
    //## operation freiner(double)
    double freiner(double brakePedal);
    
    ////    Additional operations    ////
    
    ////    Attributes    ////

protected :

    int MAX_BRAKE;		//## attribute MAX_BRAKE
    
    int MAX_SPEED;		//## attribute MAX_SPEED
    
    double MAX_THROTTLE;		//## attribute MAX_THROTTLE
    
    double airResistance;		//## attribute airResistance
    
    double brakePedal;		//## attribute brakePedal
    
    int distance;		//## attribute distance
    
    double fdist;		//## attribute fdist
    
    double fspeed;		//## attribute fspeed
    
    bool ignition;		//## attribute ignition
    
    int speed;		//## attribute speed
    
    ////    Relations and components    ////
    
    ////    Framework operations    ////
    
    double throttle;		//## attribute throttle

public :

    //## operation init()
    void init();

protected :

    bool _simu;		//## attribute _simu
    
    double accelPedal;		//## attribute accelPedal
    
    int alpha;		//## attribute alpha
    
    double error;		//## attribute error
    
    double steady;		//## attribute steady
    
    int vitesseConsigne;		//## attribute vitesseConsigne

public :

    //## auto_generated
    _SysVehicule(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~_SysVehicule();
    
    //## auto_generated
    int getMAX_BRAKE();
    
    //## auto_generated
    void setMAX_BRAKE(int p_MAX_BRAKE);
    
    //## auto_generated
    int getMAX_SPEED();
    
    //## auto_generated
    void setMAX_SPEED(int p_MAX_SPEED);
    
    //## auto_generated
    double getMAX_THROTTLE();
    
    //## auto_generated
    void setMAX_THROTTLE(double p_MAX_THROTTLE);
    
    //## auto_generated
    bool get_simu();
    
    //## auto_generated
    void set_simu(bool p__simu);
    
    //## auto_generated
    double getAccelPedal();
    
    //## auto_generated
    void setAccelPedal(double p_accelPedal);
    
    //## auto_generated
    double getAirResistance();
    
    //## auto_generated
    void setAirResistance(double p_airResistance);
    
    //## auto_generated
    int getAlpha();
    
    //## auto_generated
    void setAlpha(int p_alpha);
    
    //## auto_generated
    double getBrakePedal();
    
    //## auto_generated
    void setBrakePedal(double p_brakePedal);
    
    //## auto_generated
    int getDistance();
    
    //## auto_generated
    void setDistance(int p_distance);
    
    //## auto_generated
    double getError();
    
    //## auto_generated
    void setError(double p_error);
    
    //## auto_generated
    double getFdist();
    
    //## auto_generated
    void setFdist(double p_fdist);
    
    //## auto_generated
    double getFspeed();
    
    //## auto_generated
    void setFspeed(double p_fspeed);
    
    //## auto_generated
    bool getIgnition();
    
    //## auto_generated
    int getSpeed();
    
    //## auto_generated
    double getSteady();
    
    //## auto_generated
    void setSteady(double p_steady);
    
    //## auto_generated
    double getThrottle();
    
    //## auto_generated
    int getVitesseConsigne();
    
    //## auto_generated
    void setVitesseConsigne(int p_vitesseConsigne);
    
    //## auto_generated
    virtual bool startBehavior();
    
    //## auto_generated
    void setIgnition(bool p_ignition);
    
    //## auto_generated
    void setSpeed(int p_speed);
    
    //## auto_generated
    void setThrottle(double p_throttle);

protected :

    //## auto_generated
    void initStatechart();
    
    //## auto_generated
    void cancelTimeouts();
    
    //## auto_generated
    bool cancelTimeout(const IOxfTimeout* arg);

public :

    //## operation regulation()
    void regulation();
    
    //## auto_generated
    bool getRegulateur();
    
    //## auto_generated
    void setRegulateur(bool p_regulateur);

protected :

    bool regulateur;		//## attribute regulateur

public :

    //## operation Operation_103()
    void Operation_103();
    
    //## auto_generated
    bool getAlarme();
    
    //## auto_generated
    void setAlarme(bool p_Alarme);
    
    //## auto_generated
    bool getLED();
    
    //## auto_generated
    void setLED(bool p_LED);
    
    //## auto_generated
    double getMemoryAccel();
    
    //## auto_generated
    void setMemoryAccel(double p_MemoryAccel);
    
    //## auto_generated
    bool getVoyant();
    
    //## auto_generated
    void setVoyant(bool p_Voyant);
    
    //## auto_generated
    int getAugmentation_int_0();
    
    //## auto_generated
    void setAugmentation_int_0(int p_augmentation_int_0);
    
    //## auto_generated
    int getDiminution_int_0();
    
    //## auto_generated
    void setDiminution_int_0(int p_diminution_int_0);
    
    //## auto_generated
    bool getLimiteur();
    
    //## auto_generated
    void setLimiteur(bool p_limiteur);
    
    //## auto_generated
    int getVitesseLimite();
    
    //## auto_generated
    void setVitesseLimite(int p_vitesseLimite);

protected :

    bool Alarme;		//## attribute Alarme
    
    bool LED;		//## attribute LED
    
    double MemoryAccel;		//## attribute MemoryAccel
    
    bool Voyant;		//## attribute Voyant
    
    int augmentation_int_0;		//## attribute augmentation_int_0
    
    int diminution_int_0;		//## attribute diminution_int_0
    
    bool limiteur;		//## attribute limiteur
    
    int vitesseLimite;		//## attribute vitesseLimite

public :

    //## auto_generated
    bool getAffiche_kit_b_car();
    
    //## auto_generated
    void setAffiche_kit_b_car(bool p_affiche_kit_b_car);
    
    //## auto_generated
    bool getBluetooth();
    
    //## auto_generated
    void setBluetooth(bool p_bluetooth);
    
    //## auto_generated
    int getBouton_tel();
    
    //## auto_generated
    void setBouton_tel(int p_bouton_tel);
    
    //## auto_generated
    int getCpt_sms();
    
    //## auto_generated
    void setCpt_sms(int p_cpt_sms);
    
    //## auto_generated
    int getVContact();
    
    //## auto_generated
    void setVContact(int p_vContact);
    
    //## auto_generated
    bool getVJum();
    
    //## auto_generated
    void setVJum(bool p_vJum);
    
    //## auto_generated
    bool getVSonnerie();
    
    //## auto_generated
    void setVSonnerie(bool p_vSonnerie);
    
    //## auto_generated
    bool getVSonnerieTel();
    
    //## auto_generated
    void setVSonnerieTel(bool p_vSonnerieTel);

protected :

    bool affiche_kit_b_car;		//## attribute affiche_kit_b_car
    
    bool bluetooth;		//## attribute bluetooth
    
    int bouton_tel;		//## attribute bouton_tel
    
    int cpt_sms;		//## attribute cpt_sms
    
    int vContact;		//## attribute vContact
    
    bool vJum;		//## attribute vJum
    
    bool vSonnerie;		//## attribute vSonnerie
    
    bool vSonnerieTel;		//## attribute vSonnerieTel

public :

    //## auto_generated
    bool getAppel_en_cours();
    
    //## auto_generated
    void setAppel_en_cours(bool p_appel_en_cours);
    
    //## auto_generated
    int getVBatterie();
    
    //## auto_generated
    void setVBatterie(int p_vBatterie);
    
    //## auto_generated
    int getVBatterie_tel();
    
    //## auto_generated
    void setVBatterie_tel(int p_vBatterie_tel);

protected :

    bool appel_en_cours;		//## attribute appel_en_cours
    
    int vBatterie;		//## attribute vBatterie
    
    int vBatterie_tel;		//## attribute vBatterie_tel

public :

    // rootState:
    //## statechart_method
    inline bool rootState_IN() const;
    
    //## statechart_method
    virtual void rootState_entDef();
    
    //## statechart_method
    void rootStateEntDef();
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent();
    
    // state_82:
    //## statechart_method
    inline bool state_82_IN() const;
    
    //## statechart_method
    void state_82_entDef();
    
    //## statechart_method
    void state_82_exit();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_82_processEvent();
    
    // state_84:
    //## statechart_method
    inline bool state_84_IN() const;
    
    //## statechart_method
    void state_84_entDef();
    
    //## statechart_method
    void state_84_exit();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_84_processEvent();
    
    // Telephone:
    //## statechart_method
    inline bool Telephone_IN() const;
    
    //## statechart_method
    void Telephone_entDef();
    
    //## statechart_method
    void Telephone_exit();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus Telephone_processEvent();
    
    // state_90:
    //## statechart_method
    inline bool state_90_IN() const;
    
    //## statechart_method
    void state_90_entDef();
    
    //## statechart_method
    void state_90_exit();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_90_processEvent();
    
    // state_96:
    //## statechart_method
    inline bool state_96_IN() const;
    
    // state_95:
    //## statechart_method
    inline bool state_95_IN() const;
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_95_handleEvent();
    
    // state_94:
    //## statechart_method
    inline bool state_94_IN() const;
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_94_handleEvent();
    
    // no_battery:
    //## statechart_method
    inline bool no_battery_IN() const;
    
    // state_89:
    //## statechart_method
    inline bool state_89_IN() const;
    
    //## statechart_method
    void state_89_entDef();
    
    //## statechart_method
    void state_89_exit();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_89_processEvent();
    
    // state_79:
    //## statechart_method
    inline bool state_79_IN() const;
    
    // state_78:
    //## statechart_method
    inline bool state_78_IN() const;
    
    // state_77:
    //## statechart_method
    inline bool state_77_IN() const;
    
    // state_75:
    //## statechart_method
    inline bool state_75_IN() const;
    
    // state_74:
    //## statechart_method
    inline bool state_74_IN() const;
    
    // state_73:
    //## statechart_method
    inline bool state_73_IN() const;
    
    // jumele_tel:
    //## statechart_method
    inline bool jumele_tel_IN() const;
    
    // jumelage:
    //## statechart_method
    inline bool jumelage_IN() const;
    
    // state_83:
    //## statechart_method
    inline bool state_83_IN() const;
    
    //## statechart_method
    void state_83_entDef();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_83_processEvent();
    
    // state_4:
    //## statechart_method
    inline bool state_4_IN() const;
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_4TakeNull();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_4_handleEvent();
    
    // state_0:
    //## statechart_method
    inline bool state_0_IN() const;
    
    //## statechart_method
    void state_0_entDef();
    
    //## statechart_method
    void state_0_exit();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_0_processEvent();
    
    // state_9:
    //## statechart_method
    inline bool state_9_IN() const;
    
    //## statechart_method
    void state_9_entDef();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_9_processEvent();
    
    // contact:
    //## statechart_method
    inline bool contact_IN() const;
    
    // Allumage:
    //## statechart_method
    inline bool Allumage_IN() const;
    
    //## statechart_method
    void Allumage_entDef();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus Allumage_handleEvent();
    
    // Freinage:
    //## statechart_method
    inline bool Freinage_IN() const;
    
    //## statechart_method
    IOxfReactive::TakeEventStatus Freinage_handleEvent();
    
    // Acceleration:
    //## statechart_method
    inline bool Acceleration_IN() const;
    
    //## statechart_method
    IOxfReactive::TakeEventStatus Acceleration_handleEvent();
    
    // state_67:
    //## statechart_method
    inline bool state_67_IN() const;
    
    //## statechart_method
    void state_67_entDef();
    
    //## statechart_method
    void state_67_exit();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_67_processEvent();
    
    // state_99:
    //## statechart_method
    inline bool state_99_IN() const;
    
    // state_97:
    //## statechart_method
    inline bool state_97_IN() const;
    
    // on:
    //## statechart_method
    inline bool on_IN() const;
    
    // off:
    //## statechart_method
    inline bool off_IN() const;
    
    // jumele_car:
    //## statechart_method
    inline bool jumele_car_IN() const;
    
    //## statechart_method
    IOxfReactive::TakeEventStatus jumele_car_handleEvent();
    
    // etat_sonne:
    //## statechart_method
    inline bool etat_sonne_IN() const;
    
    //## statechart_method
    IOxfReactive::TakeEventStatus etat_sonne_handleEvent();
    
    // appel:
    //## statechart_method
    inline bool appel_IN() const;
    
    // state_49:
    //## statechart_method
    inline bool state_49_IN() const;
    
    //## statechart_method
    void state_49_entDef();
    
    //## statechart_method
    void state_49_exit();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_49_processEvent();
    
    // state_60:
    //## statechart_method
    inline bool state_60_IN() const;
    
    // state_52:
    //## statechart_method
    inline bool state_52_IN() const;
    
    // state_51:
    //## statechart_method
    inline bool state_51_IN() const;
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_51_handleEvent();
    
    // state_50:
    //## statechart_method
    inline bool state_50_IN() const;
    
    // state_32:
    //## statechart_method
    inline bool state_32_IN() const;
    
    //## statechart_method
    void state_32_entDef();
    
    //## statechart_method
    void state_32_exit();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_32_processEvent();
    
    // state_63:
    //## statechart_method
    inline bool state_63_IN() const;
    
    // state_62:
    //## statechart_method
    inline bool state_62_IN() const;
    
    // state_47:
    //## statechart_method
    inline bool state_47_IN() const;
    
    // Limitation:
    //## statechart_method
    inline bool Limitation_IN() const;
    
    //## statechart_method
    IOxfReactive::TakeEventStatus Limitation_handleEvent();
    
    // state_2:
    //## statechart_method
    inline bool state_2_IN() const;
    
    //## statechart_method
    void state_2_entDef();
    
    //## statechart_method
    void state_2_exit();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_2_processEvent();
    
    // state_13:
    //## statechart_method
    inline bool state_13_IN() const;
    
    //## statechart_method
    void state_13_entDef();
    
    //## statechart_method
    void state_13_exit();
    
    // state_13_state_13:
    //## statechart_method
    inline bool state_13_state_13_IN() const;
    
    // state_1:
    //## statechart_method
    inline bool state_1_IN() const;
    
    //## statechart_method
    void state_1_entDef();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_1_processEvent();
    
    // state_31:
    //## statechart_method
    inline bool state_31_IN() const;
    
    // state_24:
    //## statechart_method
    inline bool state_24_IN() const;
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_24_handleEvent();
    
    // state_23:
    //## statechart_method
    inline bool state_23_IN() const;

protected :

//#[ ignore
    enum _SysVehicule_Enum {
        OMNonState = 0,
        state_82 = 1,
        state_84 = 2,
        Telephone = 3,
        state_90 = 4,
        state_96 = 5,
        state_95 = 6,
        state_94 = 7,
        no_battery = 8,
        state_89 = 9,
        state_79 = 10,
        state_78 = 11,
        state_77 = 12,
        state_75 = 13,
        state_74 = 14,
        state_73 = 15,
        jumele_tel = 16,
        jumelage = 17,
        state_83 = 18,
        state_4 = 19,
        state_0 = 20,
        state_9 = 21,
        contact = 22,
        Allumage = 23,
        Freinage = 24,
        Acceleration = 25,
        state_67 = 26,
        state_99 = 27,
        state_97 = 28,
        on = 29,
        off = 30,
        jumele_car = 31,
        etat_sonne = 32,
        appel = 33,
        state_49 = 34,
        state_60 = 35,
        state_52 = 36,
        state_51 = 37,
        state_50 = 38,
        state_32 = 39,
        state_63 = 40,
        state_62 = 41,
        state_47 = 42,
        Limitation = 43,
        state_2 = 44,
        state_13 = 45,
        state_13_state_13 = 46,
        state_1 = 47,
        state_31 = 48,
        state_24 = 49,
        state_23 = 50
    };
    
    int rootState_subState;
    
    int rootState_active;
    
    int state_84_subState;
    
    int state_84_active;
    
    int state_90_subState;
    
    int state_90_active;
    
    IOxfTimeout* state_90_timeout;
    
    int state_89_subState;
    
    int state_89_active;
    
    int state_83_subState;
    
    int state_83_active;
    
    int state_9_subState;
    
    int state_9_active;
    
    IOxfTimeout* state_9_timeout;
    
    int Allumage_subState;
    
    IOxfTimeout* Allumage_timeout;
    
    int state_67_subState;
    
    int state_67_active;
    
    IOxfTimeout* state_67_timeout;
    
    int state_49_subState;
    
    int state_49_active;
    
    IOxfTimeout* state_49_timeout;
    
    int state_32_subState;
    
    int state_32_active;
    
    IOxfTimeout* state_32_timeout;
    
    int state_2_subState;
    
    int state_2_active;
    
    int state_13_subState;
    
    IOxfTimeout* state_13_timeout;
    
    int state_1_subState;
    
    int state_1_active;
    
    IOxfTimeout* state_1_timeout;
//#]
};

#ifdef _OMINSTRUMENT
DECLARE_OPERATION_CLASS(_MonPkg__SysVehicule_setAccelPedal_double)

DECLARE_OPERATION_CLASS(_MonPkg__SysVehicule_setAlpha_int)

DECLARE_OPERATION_CLASS(_MonPkg__SysVehicule_setBluetooth_bool)

DECLARE_OPERATION_CLASS(_MonPkg__SysVehicule_setBouton_tel_int)

DECLARE_OPERATION_CLASS(_MonPkg__SysVehicule_setBrakePedal_double)

DECLARE_OPERATION_CLASS(_MonPkg__SysVehicule_setLimiteur_bool)

DECLARE_OPERATION_CLASS(_MonPkg__SysVehicule_setRegulateur_bool)

DECLARE_OPERATION_CLASS(_MonPkg__SysVehicule_setVContact_int)

DECLARE_OPERATION_CLASS(_MonPkg__SysVehicule_setVitesseLimite_int)

//#[ ignore
class OMAnimated_SysVehicule : virtual public AOMInstance {
    DECLARE_REACTIVE_META(_SysVehicule, OMAnimated_SysVehicule)
    
    DECLARE_META_OP(_MonPkg__SysVehicule_setAccelPedal_double)
    
    DECLARE_META_OP(_MonPkg__SysVehicule_setAlpha_int)
    
    DECLARE_META_OP(_MonPkg__SysVehicule_setBluetooth_bool)
    
    DECLARE_META_OP(_MonPkg__SysVehicule_setBouton_tel_int)
    
    DECLARE_META_OP(_MonPkg__SysVehicule_setBrakePedal_double)
    
    DECLARE_META_OP(_MonPkg__SysVehicule_setLimiteur_bool)
    
    DECLARE_META_OP(_MonPkg__SysVehicule_setRegulateur_bool)
    
    DECLARE_META_OP(_MonPkg__SysVehicule_setVContact_int)
    
    DECLARE_META_OP(_MonPkg__SysVehicule_setVitesseLimite_int)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeAttributes(AOMSAttributes* aomsAttributes) const;
    
    //## statechart_method
    void rootState_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_82_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_84_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Telephone_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_90_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_96_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_95_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_94_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void no_battery_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_89_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_79_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_78_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_77_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_75_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_74_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_73_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void jumele_tel_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void jumelage_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_83_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_4_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_0_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_9_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void contact_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Allumage_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Freinage_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Acceleration_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_67_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_99_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_97_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void on_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void off_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void jumele_car_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void etat_sonne_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void appel_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_49_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_60_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_52_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_51_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_50_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_32_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_63_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_62_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_47_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Limitation_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_2_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_13_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_13_state_13_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_1_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_31_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_24_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_23_serializeStates(AOMSState* aomsState) const;
};
//#]
#endif // _OMINSTRUMENT

inline bool _SysVehicule::rootState_IN() const {
    return true;
}

inline bool _SysVehicule::state_82_IN() const {
    return rootState_subState == state_82;
}

inline bool _SysVehicule::state_84_IN() const {
    return state_82_IN();
}

inline bool _SysVehicule::Telephone_IN() const {
    return state_84_subState == Telephone;
}

inline bool _SysVehicule::state_90_IN() const {
    return Telephone_IN();
}

inline bool _SysVehicule::state_96_IN() const {
    return state_90_subState == state_96;
}

inline bool _SysVehicule::state_95_IN() const {
    return state_90_subState == state_95;
}

inline bool _SysVehicule::state_94_IN() const {
    return state_90_subState == state_94;
}

inline bool _SysVehicule::no_battery_IN() const {
    return state_90_subState == no_battery;
}

inline bool _SysVehicule::state_89_IN() const {
    return Telephone_IN();
}

inline bool _SysVehicule::state_79_IN() const {
    return state_89_subState == state_79;
}

inline bool _SysVehicule::state_78_IN() const {
    return state_89_subState == state_78;
}

inline bool _SysVehicule::state_77_IN() const {
    return state_89_subState == state_77;
}

inline bool _SysVehicule::state_75_IN() const {
    return state_89_subState == state_75;
}

inline bool _SysVehicule::state_74_IN() const {
    return state_89_subState == state_74;
}

inline bool _SysVehicule::state_73_IN() const {
    return state_89_subState == state_73;
}

inline bool _SysVehicule::jumele_tel_IN() const {
    return state_89_subState == jumele_tel;
}

inline bool _SysVehicule::jumelage_IN() const {
    return state_89_subState == jumelage;
}

inline bool _SysVehicule::state_83_IN() const {
    return state_82_IN();
}

inline bool _SysVehicule::state_4_IN() const {
    return state_83_subState == state_4;
}

inline bool _SysVehicule::state_0_IN() const {
    return state_83_subState == state_0;
}

inline bool _SysVehicule::state_9_IN() const {
    return state_0_IN();
}

inline bool _SysVehicule::contact_IN() const {
    return state_9_subState == contact;
}

inline bool _SysVehicule::Allumage_IN() const {
    return state_9_subState == Allumage;
}

inline bool _SysVehicule::Freinage_IN() const {
    return Allumage_subState == Freinage;
}

inline bool _SysVehicule::Acceleration_IN() const {
    return Allumage_subState == Acceleration;
}

inline bool _SysVehicule::state_67_IN() const {
    return state_0_IN();
}

inline bool _SysVehicule::state_99_IN() const {
    return state_67_subState == state_99;
}

inline bool _SysVehicule::state_97_IN() const {
    return state_67_subState == state_97;
}

inline bool _SysVehicule::on_IN() const {
    return state_67_subState == on;
}

inline bool _SysVehicule::off_IN() const {
    return state_67_subState == off;
}

inline bool _SysVehicule::jumele_car_IN() const {
    return state_67_subState == jumele_car;
}

inline bool _SysVehicule::etat_sonne_IN() const {
    return state_67_subState == etat_sonne;
}

inline bool _SysVehicule::appel_IN() const {
    return state_67_subState == appel;
}

inline bool _SysVehicule::state_49_IN() const {
    return state_0_IN();
}

inline bool _SysVehicule::state_60_IN() const {
    return state_49_subState == state_60;
}

inline bool _SysVehicule::state_52_IN() const {
    return state_49_subState == state_52;
}

inline bool _SysVehicule::state_51_IN() const {
    return state_49_subState == state_51;
}

inline bool _SysVehicule::state_50_IN() const {
    return state_49_subState == state_50;
}

inline bool _SysVehicule::state_32_IN() const {
    return state_0_IN();
}

inline bool _SysVehicule::state_63_IN() const {
    return state_32_subState == state_63;
}

inline bool _SysVehicule::state_62_IN() const {
    return state_32_subState == state_62;
}

inline bool _SysVehicule::state_47_IN() const {
    return state_32_subState == state_47;
}

inline bool _SysVehicule::Limitation_IN() const {
    return state_32_subState == Limitation;
}

inline bool _SysVehicule::state_2_IN() const {
    return state_0_IN();
}

inline bool _SysVehicule::state_13_IN() const {
    return state_2_subState == state_13;
}

inline bool _SysVehicule::state_13_state_13_IN() const {
    return state_13_subState == state_13_state_13;
}

inline bool _SysVehicule::state_1_IN() const {
    return state_0_IN();
}

inline bool _SysVehicule::state_31_IN() const {
    return state_1_subState == state_31;
}

inline bool _SysVehicule::state_24_IN() const {
    return state_1_subState == state_24;
}

inline bool _SysVehicule::state_23_IN() const {
    return state_1_subState == state_23;
}

#endif
/*********************************************************************
	File Path	: CodesGeneres\ModeAnimation\_SysVehicule.h
*********************************************************************/
