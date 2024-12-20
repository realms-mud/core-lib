//*****************************************************************************
// Class: biological
// File Name: biological.c
//
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
// Description: This object encapsulates all functionality surrounding the
//              biological aspects of living creatures - specifically
//              how much they have consumed and the toxicity of said 
//              consumables.
//
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/biological.h"

//-----------------------------------------------------------------------------
// Method: validBiological
// Description: The valid* methods are admittedly a bit of a misnomer. The real
//              intent is to list all of the calculated bonuses used in combat
//              that are controlled by this object. It is only accessible
//              within the inheritance tree.
//
// Returns: the list of bonus methods controlled by this object
//-----------------------------------------------------------------------------
static nomask string *validBiological()
{
    return ({ "bonus to intoxication", "bonus to stuffed", "bonus to drugged",
              "bonus to soaked", "bonus headache" });
}

//-----------------------------------------------------------------------------
// Method: biologicalNotification
// Description: This method is used to broadcast all biological-related events
//              as they occur. See events.c for details.
//
// Parameters: event - the event that has occured. 
//-----------------------------------------------------------------------------
private nomask void biologicalNotification(string event)
{
    object eventObj = getService("events");
    
    if(event && stringp(event) && eventObj && objectp(eventObj))
    {
        eventObj->notify(event);
    }
}

//-----------------------------------------------------------------------------
// Method: Intoxicated
// Description: This property will allow other entities to get/set the
//              intoxicated level. if intoxLevel is passed, the intoxicated
//              value is altered to be that value.
//
// Parameters: intoxLevel - the optional value to apply
//
// Returns: the level of intoxication
//-----------------------------------------------------------------------------   
public varargs int Intoxicated(int intoxLevel)
{
    if(intoxLevel && intp(intoxLevel) && (intoxLevel > 0))
    {
        intoxicated = intoxLevel;
        biologicalNotification("onIntoxicationChanged");
    }
    return intoxicated;
}

//-----------------------------------------------------------------------------
// Method: calculateBiologicalModifier
// Description: This internal method will apply valueToAdd to the passed-in 
//              originalValue. If the passed valueToAdd is negative, the added
//              value is normalized based on the old lib's functionality.
//
// Parameters: originalValue - the value of the bio type that will be modified
//             valueToAdd - the value to apply to originalValue
//
// Returns: the updated value of the bio stat
//-----------------------------------------------------------------------------
private nomask int calculateBiologicalModifier(int originalValue, int valueToAdd)
{
    int ret = intp(originalValue) ? originalValue : 0;
    if(valueToAdd && intp(valueToAdd))
    {
        ret += valueToAdd;
        
        if(ret < 0)
        {
            ret = 0;
        }
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: addIntoxication
// Description: This method will apply intoxToAdd to the current intoxicated
//              value.
//
// Parameters: intoxToAdd - the value to apply to intoxicated
//
// Returns: the updated value of the bio stat
//-----------------------------------------------------------------------------
public nomask int addIntoxication(int intoxToAdd)
{
    int ret = 0;

    if(intoxToAdd && intp(intoxToAdd))
    {
        ret = 1;
        intoxicated = calculateBiologicalModifier(intoxicated, intoxToAdd);
        biologicalNotification("onIntoxicationChanged");
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: Stuffed
// Description: This property will allow other entities to get/set the
//              stuffed level. if stuffedLevel is passed, the stuffed
//              value is altered to be that value.
//
// Parameters: stuffedLevel - the optional value to apply
//
// Returns: the level of stuffed
//-----------------------------------------------------------------------------   
public varargs int Stuffed(int stuffedLevel)
{
    if(stuffedLevel && intp(stuffedLevel) && (stuffedLevel > 0))
    {
        stuffed = stuffedLevel;
        biologicalNotification("onStuffedChanged");
    }
    return stuffed;
}

//-----------------------------------------------------------------------------
// Method: addStuffed
// Description: This method will apply stuffedLevel to the current stuffed
//              value.
//
// Parameters: stuffedLevel - the value to apply to stuffed
//
// Returns: the updated value of the bio stat
//-----------------------------------------------------------------------------
public nomask int addStuffed(int stuffedLevel)
{
    int ret = 0;
    if(stuffedLevel && intp(stuffedLevel))
    {
        ret = 1;
        stuffed = calculateBiologicalModifier(stuffed, stuffedLevel);
        biologicalNotification("onStuffedChanged");
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: Drugged
// Description: This property will allow other entities to get/set the
//              drugged level. if druggedLevel is passed, the drugged
//              value is altered to be that value.
//
// Parameters: druggedLevel - the optional value to apply
//
// Returns: the level of drugged
//-----------------------------------------------------------------------------   
public varargs int Drugged(int druggedLevel)
{
    if(druggedLevel && intp(druggedLevel) && (druggedLevel > 0))
    {
        drugged = druggedLevel;
        biologicalNotification("onDruggedChanged");
    }
    return drugged;
}

//-----------------------------------------------------------------------------
// Method: addDrugged
// Description: This method will apply druggedLevel to the current drugged
//              value.
//
// Parameters: druggedLevel - the value to apply to drugged
//
// Returns: the updated value of the bio stat
//-----------------------------------------------------------------------------
public nomask int addDrugged(int druggedLevel)
{
    int ret = 0;
    if(druggedLevel && intp(druggedLevel))
    {
        ret = 1;
        drugged = calculateBiologicalModifier(drugged, druggedLevel);
        biologicalNotification("onDruggedChanged");
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: Soaked
// Description: This property will allow other entities to get/set the
//              soaked level. if soakedLevel is passed, the soaked
//              value is altered to be that value.
//
// Parameters: soakedLevel - the optional value to apply
//
// Returns: the level of soaked
//-----------------------------------------------------------------------------   
public varargs int Soaked(int soakedLevel)
{
    if(soakedLevel && intp(soakedLevel) && (soakedLevel > 0))
    {
        soaked = soakedLevel;
        biologicalNotification("onSoakedChanged");
    }
    return soaked;
}

//-----------------------------------------------------------------------------
// Method: addSoaked
// Description: This method will apply soakedLevel to the current soaked
//              value.
//
// Parameters: soakedLevel - the value to apply to soaked
//
// Returns: the updated value of the bio stat
//-----------------------------------------------------------------------------
public nomask int addSoaked(int soakedLevel)
{
    int ret = 0;
    if(soakedLevel && intp(soakedLevel))
    {
        ret = 1;
        soaked = calculateBiologicalModifier(soaked, soakedLevel);
        biologicalNotification("onSoakedChanged");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int getMaximumBiologicalLevel(string type)
{
    int ret = 0;
    foreach(string service in({ "guilds", "races", "traits" }))
    {
        object serviceObject = getService(service);
        if (serviceObject && function_exists("biologicalModifier"))
        {
            ret += serviceObject->biologicalModifier(type);
        }
    }

    object attributes = getService("attributes");
    if (attributes)
    {
        ret += attributes->Con() * 2;
    }

    object inventory = getService("inventory");
    if (inventory)
    {
        ret += inventory->inventoryGetModifier("biological",
            sprintf("bonus to %s", type));
    }

    return ret;
}

//-----------------------------------------------------------------------------
// Method: drinkAlcohol
// Description: This method should be executed by external entities every time
//              that a living attempts to consume an alcoholic beverage. When 
//              this occurs, it will determine whether or not the item can
//              be consumed based on attribute and equipment bonuses. It will
//              also handle the resolution of headache for intox/drug usage.
//
// Parameters: drink - the consumed item.
//
// Returns: true if the item can be consumed.
//-----------------------------------------------------------------------------
public nomask int drinkAlcohol(object drink)
{
    int ret = 0;
    int maxIntox = getMaximumBiologicalLevel("intoxication");

    if (Intoxicated() > maxIntox)
    {
        tell_object(this_object(), "You fail to reach the drink with your mouth.\n");
    }
    else if (objectp(drink) && (member(inherit_list(drink), "/lib/items/drink.c") > -1))
    {
        ret = 1;
        intoxicated += drink->query("biological strength");
        if (intoxicated >= maxIntox)
        {
            tell_object(this_object(), "You feel completely inebriated.\n");
            biologicalNotification("onDrunk");
        }
        else if(intoxicated <= 0)
        {
            intoxicated = 0;
            tell_object(this_object(), "You are completely sober.\n");
            biologicalNotification("onSober");
        }
        getDictionary("biological")->applyBiologicalEffect(this_object(), 
            drink);
   }    
    return ret;
}

//-----------------------------------------------------------------------------
// Method: consumeDrug
// Description: This method should be executed by external entities every time
//              that a living attempts to consume a 'drug' item. When 
//              this occurs, it will determine whether or not the item can
//              be consumed based on attribute and equipment bonuses. It will
//              also handle the resolution of headache for intox/drug usage.
//
// Parameters: drug - the consumed item.
//
// Returns: true if the item can be consumed.
//-----------------------------------------------------------------------------
public nomask int consumeDrug(object drug)
{
    int ret = 0;
    int maxDrugged = getMaximumBiologicalLevel("drugged");

    if(Drugged() > maxDrugged)
    {
        tell_object(this_object(), "You fail to reach your mouth.\n");
    }
    else if (objectp(drug) && (member(inherit_list(drug), "/lib/items/food.c") > -1))
    {
        ret = 1;
        drugged += drug->query("biological strength");
        if (drugged >= maxDrugged)
        {
            tell_object(this_object(), "You feel completely wasted.\n");
            biologicalNotification("onWastedOnDrugs");
        }
        else if(drugged <= 0)
        {
            drugged = 0;
            tell_object(this_object(), "You are completely free of drugs.\n");
            biologicalNotification("onNoLongerDrugged");
        }
        getDictionary("biological")->applyBiologicalEffect(this_object(), 
            drug);
    }    
    return ret;
}

//-----------------------------------------------------------------------------
// Method: drink
// Description: This method should be executed by external entities every time
//              that a living attempts to consume a non-alcoholic beverage.
//              When this occurs, it will determine whether or not the item can
//              be consumed based on attribute and equipment bonuses. 
//
// Parameters: drink - the consumed item.
//
// Returns: true if the item can be consumed.
//-----------------------------------------------------------------------------
public nomask int drink(object drink)
{
    int ret = 0;
    int maxSoak = getMaximumBiologicalLevel("soaked");
    
    if(Soaked() > maxSoak)
    {
        tell_object(this_object(), "You can't possibly drink that much right now!\n"
            "You feel crosslegged enough as it is.\n");
    }
    else if(objectp(drink) && (member(inherit_list(drink), "/lib/items/drink.c") > -1))
    {
        ret = 1;
        soaked += drink->query("biological strength");
        if (soaked >= maxSoak)
        {
            tell_object(this_object(), "You feel like your bladder is going to explode.\n");
            biologicalNotification("onSoaked");
        }
        else if(soaked <= 0)
        {
            soaked = 0;
            tell_object(this_object(), "You feel a bit dry in the mouth.\n");
            biologicalNotification("onNoLongerSoaked");
        }
        getDictionary("biological")->applyBiologicalEffect(this_object(), 
            drink);
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: eat
// Description: This method should be executed by external entities every time
//              that a living attempts to consume a non-drug 'food'.
//              When this occurs, it will determine whether or not the item can
//              be consumed based on attribute and equipment bonuses. 
//
// Parameters: food - the consumed item.
//
// Returns: true if the item can be consumed.
//-----------------------------------------------------------------------------
public nomask int eat(object food)
{
    int ret = 0;
    int maxStuffed = getMaximumBiologicalLevel("stuffed");

    if(Stuffed() > maxStuffed)
    {
        tell_object(this_object(), "This is much too rich for you right now! "
            "Perhaps something lighter?\n");
    }
    else if (objectp(food) && (member(inherit_list(food), "/lib/items/food.c") > -1))
    {
        ret = 1;
        stuffed += food->query("biological strength");
        if (stuffed >= maxStuffed)
        {
            tell_object(this_object(), "You feel full.\n");
            biologicalNotification("onCannotEatMore");
        }
        else if(stuffed <= 0)
        {
            stuffed = 0;
            tell_object(this_object(), "Your stomach makes a rumbling sound.\n");
            biologicalNotification("onHungry");
        }
        getDictionary("biological")->applyBiologicalEffect(this_object(), 
            food);
    }    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void addToxicity(int value)
{

}

/////////////////////////////////////////////////////////////////////////////
public nomask int Toxicity()
{
    return 0;
}

//-----------------------------------------------------------------------------
// Method: displayBiologicalMessage
// Description: This method parses and displays a message for use by 
//              drunk/drugged heartbeat processing.
//
// Parameters: message - the message to parse and display
//-----------------------------------------------------------------------------
private nomask void displayBiologicalMessage(string message)
{
    object parser = getMessageParser();
    if(parser)
    {
        int isSecondPerson = 1;
        string userMessage = parser->parseTargetInfo(message, "User", 
            this_object(), isSecondPerson);
        userMessage = parser->parseVerbs(userMessage, isSecondPerson);
        userMessage = parser->capitalizeSentences(userMessage);
        tell_object(this_object(), sprintf("%s\n", userMessage));
        
        isSecondPerson = 0;
        string everoneElseMessage = parser->parseTargetInfo(message, 
            "User", this_object(), isSecondPerson);
        everoneElseMessage = 
            parser->parseVerbs(everoneElseMessage, isSecondPerson);
        everoneElseMessage = 
            parser->capitalizeSentences(everoneElseMessage);
        say(sprintf("%s\n", everoneElseMessage));
    }
}

//-----------------------------------------------------------------------------
// Method: determineIfIntoxicationCausesAction
// Description: This method determines whether or not to display a message 
//              while this object bumbles around in a drunken stupor. It has a
//              chance to generate a message and pass it to the parser. 
//-----------------------------------------------------------------------------
private nomask void determineIfIntoxicationCausesAction()
{
    if(intoxicated && !random(20))
    {
        string *actions = ({ "hiccup", "stumble", "stagger", "lurch", "dither",
                             "falter", "pitch", "teeter", "sway", "wobble", 
                             "waver", "burp", "totter" });
        string message = sprintf("##UserName## ##Infinitive::%s## drunkenly.", 
            actions[random(sizeof(actions))]);
        
        displayBiologicalMessage(message);
    }
}

//-----------------------------------------------------------------------------
// Method: determineIfDruggedCausesAction
// Description: This method determines whether or not to display a message 
//              while this object bumbles around in a drugged haze. It has a
//              chance to generate a message and pass it to the parser. 
//-----------------------------------------------------------------------------
private nomask void determineIfDruggedCausesAction()
{
    if(drugged && !random(20))
    {
        string *actions = ({ "stumble", "stagger", "lurch", "dither",
                             "falter", "pitch", "teeter", "sway", "wobble", 
                             "waver", "totter" });
        string message = 
            sprintf("##UserName## ##Infinitive::%s## as though drugged.",
            actions[random(sizeof(actions))]);
        
        displayBiologicalMessage(message);
    }
}

//-----------------------------------------------------------------------------
// Method: haveHeadache
// Description: This method returns whether or not the object currently has a
//              headache.
//
// Returns: true if the object has a headache.
//-----------------------------------------------------------------------------
public nomask int haveHeadache()
{
    return headache > 0;
}

//-----------------------------------------------------------------------------
// Method: biologicalHeartBeat
// Description: (no, not a real biological heart beat in any sense of the term)
//              This method is executed every two seconds via heart beat and
//              handles the erosion of the various biological attributes.
//              Currently, headache does nothing other than spit out a few
//              messages. We may wish to give it tangible negative effects.
//              This can be detrmined by a call to the haveHeadache method.
//-----------------------------------------------------------------------------
static nomask void biologicalHeartBeat()
{
    if (headache > 0)
    {
        headache--;
        if (!headache)
        {
            tell_object(this_object(), "Your headache disappears.\n");
            biologicalNotification("onDetoxified");
        }
    }
    else
    {
        headache = 0;
    }

    if(intoxicated > 0)
    {
        intoxicated--;        
        determineIfIntoxicationCausesAction();
        if(!intoxicated)
        {
            tell_object(this_object(), "You suddenly without reason get a bad headache.\n");
            headache = maxHeadache;
            biologicalNotification("onBeginDetox");
        }
    }
    else
    {
        intoxicated = 0;
    }

    if(drugged > 0)
    {
        drugged--;        
        determineIfDruggedCausesAction();
        if(!drugged)
        {
            tell_object(this_object(), "You suddenly without reason get a bad headache.\n");
            headache = maxHeadache;
            biologicalNotification("onBeginDetox");
        }        
    }
    else
    {
        drugged = 0;
    }

    if(soaked > 0)
    {
        soaked--; 
        
        if(!soaked)
        {
            tell_object(this_object(), "You feel a bit dry in the mouth.\n");
            biologicalNotification("onNoLongerSoaked");
        }
    }
    else
    {
        soaked = 0;
    }

    if(stuffed > 0)
    {
        stuffed--;
        
        if(!stuffed)
        {
            tell_object(this_object(), "Your stomach makes a rumbling sound.\n");
            biologicalNotification("onHungry");
        }
    }
    else
    {
        stuffed = 0;
    }       
}
