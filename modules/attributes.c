//*****************************************************************************
// Class: attributes
// File Name: attributes.c
//
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
// Description: This object encapsulates all functionality surrounding the
//              game-changing attributes of living creatures - specifically
//              strength, intelligence, dexterity, wisdom, constitution, and
//              charisma.
//
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/attributes.h"

private string rowFormat = "[0;31m|[0m[0;36m%12s:[0m [0;32m%-11s[0m [0;36m%12s:[0m [0;32m%-11s[0m [0;36m%12s:[0m [0;32m%-11s[0m[0;31m|[0m\n";

//-----------------------------------------------------------------------------
// Method: validAttributes
// Description: The valid* methods are admittedly a bit of a misnomer. The real
//              intent is to list all of the calculated bonuses used in combat
//              that are controlled by this object. It is only accessible
//              within the inheritance tree.
//
// Returns: the list of bonus methods controlled by this object
//-----------------------------------------------------------------------------
static nomask string *validAttributes()
{
    return ({ "bonus strength", "bonus intelligence", "bonus dexterity",
              "bonus wisdom", "bonus constitution", "bonus charisma" });
}

//-----------------------------------------------------------------------------
// Method: attributeValue
// Description: This method is used to calculate an attribute's
//              value. In addition to the value maintained by this object, it
//              also applies any racial or trait modifiers and scans inventory
//              for a list of all equipment/registered objects that might
//              apply a bonus.
//
// Parameters: attribute - the name of the attribute that is being looked up
//
// Returns: the supplied attribute's value
//-----------------------------------------------------------------------------
public varargs nomask int attributeValue(string attribute, int useRaw)
{
    int value = 0;
    
    if(attribute && stringp(attribute) &&
       (member(validAttributes(), sprintf("bonus %s", attribute)) > -1))
    {
        switch(attribute)
        {
            case "strength":
            {
                value = strength;
                break;
            }
            case "intelligence":
            {
                value = intelligence;
                break;
            }
            case "dexterity":
            {
                value = dexterity;
                break;
            }
            case "wisdom":
            {
                value = wisdom;
                break;
            }
            case "constitution":
            {
                value = constitution;
                break;
            }
            case "charisma":
            {
                value = charisma;
                break;
            }
            default:
            {
                value = 0;
                break;
            }
        }

        if (!useRaw)
        {
            string *servicesToCheck = ({ "inventory", "races", "research",
                "traits" });

            foreach(string serviceToCheck : servicesToCheck)
            {
                object service = getService(serviceToCheck);
                if (service)
                {
                    value += call_other(service,
                        sprintf("%sAttributeBonus", serviceToCheck), attribute);
                }
            }

            object room = environment(this_object());
            if (room && (member(inherit_list(room), "lib/environment/environment.c") > -1))
            {
                value += room->environmentalAttributeBonus(attribute,
                    this_object());
            }
        }
    }
      
    return value;
}

//-----------------------------------------------------------------------------
// Method: calculateUpdatedStat
// Description: This internal method will apply newVal to the passed-in stat
//              value, either by resetting or incrementing, depending of the
//              passed flag.
//
// Parameters: stat - the value of the stat that will potentially be modified
//             newVal - the value to apply to 'stat'
//             flags - true for an incremental addition, false for overwrite
//
// Returns: the updated value of the stat
//-----------------------------------------------------------------------------
private nomask int calculateUpdatedStat(int stat, int newVal, int flags)
{
    int value = stat;
    
    if(newVal && intp(newVal))
    {
        if(flags && intp(flags) && (flags == IncrementAttribute))
        {
            value += newVal;
        }
        else
        {
            value = newVal;
        }
    }
    return value;
}

//-----------------------------------------------------------------------------
// Method: Str
// Description: This property will allow other entities to get/set the strength
//              attribute. If a newStr parameter is passed, the value is either
//              replaced or updated depending on the value of the flags 
//              parameter. External bonuses are applied via the attributeValue
//              method call.
//
// Parameters: newVal - the optional value to apply
//             flags - true for an incremental addition, false for overwrite
//
// Returns: the strength attribute
//-----------------------------------------------------------------------------
public nomask varargs int Str(int newStr, int flags)
{
    strength = calculateUpdatedStat(strength, newStr, flags);
    return attributeValue("strength");
}

//-----------------------------------------------------------------------------
// Method: Int
// Description: This property will allow other entities to get/set the 
//              intelligence attribute. If a newStr parameter is passed, the 
//              value is either replaced or updated depending on the value of
//              the flags parameter.External bonuses are applied via the 
//              attributeValue method call.
//
// Parameters: newVal - the optional value to apply
//             flags - true for an incremental addition, false for overwrite
//
// Returns: the intelligence attribute
//-----------------------------------------------------------------------------
public nomask varargs int Int(int newInt, int flags)
{
    intelligence = calculateUpdatedStat(intelligence, newInt, flags);
    return attributeValue("intelligence");
}

//-----------------------------------------------------------------------------
// Method: Dex
// Description: This property will allow other entities to get/set the 
//              dexterity attribute. If a newStr parameter is passed, the 
//              value is either replaced or updated depending on the value of
//              the flags parameter.External bonuses are applied via the 
//              attributeValue method call.
//
// Parameters: newVal - the optional value to apply
//             flags - true for an incremental addition, false for overwrite
//
// Returns: the dexterity attribute
//-----------------------------------------------------------------------------
public nomask varargs int Dex(int newDex, int flags)
{
    dexterity = calculateUpdatedStat(dexterity, newDex, flags);
    return attributeValue("dexterity");
}

//-----------------------------------------------------------------------------
// Method: Wis
// Description: This property will allow other entities to get/set the wisdom
//              attribute. If a newStr parameter is passed, the value is either
//              replaced or updated depending on the value of the flags 
//              parameter. External bonuses are applied via the attributeValue
//              method call.
//
// Parameters: newVal - the optional value to apply
//             flags - true for an incremental addition, false for overwrite
//
// Returns: the wisdom attribute
//-----------------------------------------------------------------------------
public nomask varargs int Wis(int newWis, int flags)
{
    wisdom = calculateUpdatedStat(wisdom, newWis, flags);
    return attributeValue("wisdom");
}

//-----------------------------------------------------------------------------
// Method: Con
// Description: This property will allow other entities to get/set the 
//              constitution attribute. If a newStr parameter is passed, the 
//              value is either replaced or updated depending on the value of
//              the flags parameter.External bonuses are applied via the 
//              attributeValue method call.
//
// Parameters: newVal - the optional value to apply
//             flags - true for an incremental addition, false for overwrite
//
// Returns: the constitution attribute
//-----------------------------------------------------------------------------
public nomask varargs int Con(int newCon, int flags)
{
    constitution = calculateUpdatedStat(constitution, newCon, flags);
    return attributeValue("constitution");
}

//-----------------------------------------------------------------------------
// Method: Chr
// Description: This property will allow other entities to get/set the 
//              charisma attribute. If a newStr parameter is passed, the 
//              value is either replaced or updated depending on the value of
//              the flags parameter.External bonuses are applied via the 
//              attributeValue method call.
//
// Parameters: newVal - the optional value to apply
//             flags - true for an incremental addition, false for overwrite
//
// Returns: the charisma attribute
//-----------------------------------------------------------------------------
public nomask varargs int Chr(int newChr, int flags)
{
    charisma = calculateUpdatedStat(charisma, newChr, flags);
    return attributeValue("charisma");
}

//-----------------------------------------------------------------------------
// Method: bonusForAttribute
// Description: This internal method returns the derived bonus for the supplied
//              stat.
//
// Parameters: attribute - the attribute whose bonus value is to be calculated
//
// Returns: the bonus for the supplied stat
//-----------------------------------------------------------------------------
private nomask int bonusForAttribute(string attribute)
{
    int bonus = 0;
    
    if(attribute && stringp(attribute) &&
       (member(validAttributes(), sprintf("bonus %s", attribute)) > -1))
    {
        // TODO [98]: Revise this formula that was pulled out of... a dark place.
        bonus = (attributeValue(attribute) - 10) / 2;
    }
    return bonus;
}

//-----------------------------------------------------------------------------
// Method: strengthBonus
// Description: This method returns the derived bonus for the strength
//              attribute.
//
// Returns: the strength bonus
//-----------------------------------------------------------------------------
public nomask int strengthBonus()
{    
    return bonusForAttribute("strength");
}

//-----------------------------------------------------------------------------
// Method: intelligenceBonus
// Description: This method returns the derived bonus for the intelligence
//              attribute.
//
// Returns: the intelligence bonus
//-----------------------------------------------------------------------------
public nomask int intelligenceBonus()
{
    return bonusForAttribute("intelligence");
}

//-----------------------------------------------------------------------------
// Method: dexterityBonus
// Description: This method returns the derived bonus for the dexterity
//              attribute.
//
// Returns: the dexterity bonus
//-----------------------------------------------------------------------------
public nomask int dexterityBonus()
{
    return bonusForAttribute("dexterity");
}

//-----------------------------------------------------------------------------
// Method: wisdomBonus
// Description: This method returns the derived bonus for the wisdom
//              attribute.
//
// Returns: the wisdom bonus
//-----------------------------------------------------------------------------
public nomask int wisdomBonus()
{
    return bonusForAttribute("wisdom");
}

//-----------------------------------------------------------------------------
// Method: constitutionBonus
// Description: This method returns the derived bonus for the constitution
//              attribute.
//
// Returns: the constitution bonus
//-----------------------------------------------------------------------------
public nomask int constitutionBonus()
{
    return bonusForAttribute("constitution");
}

//-----------------------------------------------------------------------------
// Method: charismaBonus
// Description: This method returns the derived bonus for the charisma
//              attribute.
//
// Returns: the charisma bonus
//-----------------------------------------------------------------------------
public nomask int charismaBonus()
{
    return bonusForAttribute("charisma");
}

//-----------------------------------------------------------------------------
// Method: addAttributePointsToSpend
// Description: This method allows derived objects that contain guilds and the
//              like the ability to add generic, 'spendable' attribute points
//              that can be applied by the spendAttributePoints method - for
//              example, this would occur during level advancement.
//
// Parameters: amount - the additional points to add to availableAttributePoints 
//
// Returns: the new value of availableAttributePoints
//-----------------------------------------------------------------------------
public nomask int addAttributePointsToSpend(int amount)
{
    return availableAttributePoints += amount;
}

//-----------------------------------------------------------------------------
// Method: spendAttributePoints
// Description: This method allows external objects to add pooled
//              availableAttributePoints of the specified amount to the specified
//              attribute.
//
// Parameters: attribute - the attribute to spend points advancing.
//             amount - the points to add to the specified attribute
//
// Returns: the new value of the modified attribute
//-----------------------------------------------------------------------------
public nomask int spendAttributePoints(string attribute, int amount)
{
    int ret = 0;
    if(attribute && stringp(attribute) && intp(amount) &&
      (availableAttributePoints >= amount) && function_exists("effectiveLevel") &&
      (((amount + attributeValue(attribute,1)) <= this_object()->effectiveLevel()) ||
      ((amount + attributeValue(attribute,1)) <= 10)))
    {
        switch(attribute)
        {
            case "strength":
            {
                ret = Str(amount, IncrementAttribute);
                break;
            }
            case "dexterity":
            {
                ret = Dex(amount, IncrementAttribute);
                break;
            }
            case "intelligence":
            {
                ret = Int(amount, IncrementAttribute);
                break;
            }
            case "wisdom":
            {
                ret = Wis(amount, IncrementAttribute);
                break;
            }
            case "constitution":
            {
                ret = Con(amount, IncrementAttribute);
                break;
            }
            case "charisma":
            {
                ret = Chr(amount, IncrementAttribute);
                break;
            }
        }
        availableAttributePoints -= amount;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int attributePoints()
{
    return availableAttributePoints;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string attributeDetails(string attribute)
{
    int actual = attributeValue(attribute);
    int raw = attributeValue(attribute, 1);

    string format = "[0;%sm%-6s[0m[0;%sm%-5s[0m";
    string statColor = "32";
    string bonusColor = "32";
    string bonusDesc = "";
    if (actual > raw)
    {
        statColor = "33;1";
        bonusColor = "34;1";
        bonusDesc = "(+" + (actual - raw) + ")";
    }
    else if (actual < raw)
    {
        statColor = "31;1";
        bonusColor = "31";
        bonusDesc = "(" + (actual - raw) + ")";
    }

    return sprintf(format, statColor, to_string(actual), bonusColor,
        bonusDesc);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string attributes()
{
    return sprintf(rowFormat, "Strength", attributeDetails("strength"),
            "Intelligence", attributeDetails("intelligence"),
            "Wisdom", attributeDetails("wisdom")) +
        sprintf(rowFormat, "Dexterity", attributeDetails("dexterity"),
            "Constitution", attributeDetails("constitution"),
            "Charisma", attributeDetails("charisma"));
}
