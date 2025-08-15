//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/combat.h"

private mapping combatCache = ([]);
private mapping combatSummaryDetails = ([]);

//-----------------------------------------------------------------------------
// Method: combatDelay
// Description: This property is used to determine if an interactive object can
//              attack. While it it greater than 0, this object will not
//              attack from within the attack() method.
//
// Parameters: delay - optional delay to add to the current combat delay
//
// Returns: the current combat delay.
//-----------------------------------------------------------------------------
public nomask varargs int combatDelay(int delay)
{
    if(delay > 0)
    {
        combatDelay += delay;
    }
    return combatDelay;
}

//-----------------------------------------------------------------------------
// Method: attackObject
// Description: This method returns the attacks dictionary - used for
//              determining damage attack types, messages, and so on.
//
// Returns: the attacks dictionary
//-----------------------------------------------------------------------------
private nomask object attackObject()
{
    return getDictionary("attacks");
}

//-----------------------------------------------------------------------------
// Method: spellAction
// Description: This property is used to determine if an interactive object can
//              execute a combat-related action such as combat, equipping /
//              unequipping items, and casting spells.
//
// Parameters: delay - optional delay to add to the current combat delay
//
// Returns: the current spell action delay.
//-----------------------------------------------------------------------------
public nomask varargs int spellAction(int delay)
{
    if(delay > 0)
    {
        spellAction += delay;
    }
    return spellAction;
}

//-----------------------------------------------------------------------------
// Method: validCombatModifiers
// Description: The valid* methods are admittedly a bit of a misnomer. The real
//              intent is to list all of the calculated bonuses used in combat
//              that are controlled by this object. It is only accessible
//              within the inheritance tree.
//
// Returns: the list of bonus methods controlled by this object
//-----------------------------------------------------------------------------
static nomask string *validCombatModifiers()
{
    return ({ "armor class", "defense class", "bonus attack", "soak",
        "encumberance", "skill penalty", "bonus defense", "haste", "slow",
        "enfeebled", "fortified", "poison", "paralysis", "disease",
        "bonus spell points", "bonus stamina points", "bonus heal hit points rate", 
        "bonus heal hit points", "bonus heal spell points", "bonus hit points",
        "bonus heal spell points rate", "bonus heal stamina",
        "bonus heal stamina rate", "damage reflection",
        "bonus defense class", "bonus damage", "bonus weapon attack",
        "bonus resist bludgeon", "bonus resist fire", "bonus resist evil", 
        "bonus resist neutral", "bonus resist physical", "bonus resist slash", 
        "bonus resist air", "bonus resist acid", "bonus resist disease", 
        "bonus resist good", "bonus resist magical", "bonus resist energy", 
        "bonus resist electricity", "bonus resist thrust", "bonus resist sonic",
        "bonus resist arrow", "bonus resist bolt", "bonus resist bullet",
        "bonus resist chaos", "bonus resist earth", "bonus resist paralysis", 
        "bonus resist psionic", "bonus resist poison", "bonus resist undead", 
        "bonus resist water", "bonus resist cold" });
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *combatEffectModifiers()
{
    return ({ "haste", "slow", "enfeebled", "fortified", "poison",
        "paralysis", "disease", "damage reflection" });
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isNegativeCombatModifier(string modifier)
{
    return member(({ "slow", "enfeebled", "poison", "paralysis",
        "disease" }), modifier) > -1;
}

//-----------------------------------------------------------------------------
// Method: combatNotification
// Description: This method is used to broadcast all combat-related events
//              as they occur. See events.c for details.
//
// Parameters: event - the event that has occured. 
//-----------------------------------------------------------------------------
private nomask varargs void combatNotification(string event, mixed message, int synchronous)
{
    object eventObj = getModule("events");
    
    if(event && stringp(event) && eventObj && objectp(eventObj))
    {
        if (synchronous)
        {
            eventObj->notifySynchronous(event, message);
        }
        else
        {
            eventObj->notify(event, message);
        }
    }
}

//-----------------------------------------------------------------------------
// Method: calculateServiceBonuses
// Description: This method will scan through the various non-inventory 
//              services that might have combat-related modifiers and applies
//              the relevant bonus. For example, where methodToCheck is set
//              to MaxHitPoints, this method calls through races, guilds, and
//              so on to determine the total bonus applied to the maxHitPoints
//              value.
//
// Parameters: methodToCheck - the type of bonus for which to check
//
// Returns: the total bonus for methodToCheck
//-----------------------------------------------------------------------------
private nomask int calculateServiceBonuses(string methodToCheck)
{
    int ret = 0;
    
    string *servicesToCheck = ({ "races", "guilds", "research", "traits",
                                 "background" });
    
    foreach(string serviceToCheck in servicesToCheck)
    {
        object service = getModule(serviceToCheck);
        if(service)
        {
            ret += call_other(service, 
                   sprintf("%sBonusTo", serviceToCheck), methodToCheck);
        }
    }
    
    object room = environment(this_object());
    if(room && (member(inherit_list(room), "/lib/environment/environment.c") > -1))
    {
        // this_object is passed as a type check - meaning that environmental
        // affects are not always applied to everything equally - there may
        // be a faction limitation, race, guild, or perhaps only non-NPCs are
        // given a benefit, monsters given a penalty, etc...
        ret += room->environmentalBonusTo(methodToCheck, this_object());
    }
    return ret;
}   

//-----------------------------------------------------------------------------
// Method: maxHitPoints
// Description: This method returns the effective total maximum hit points that
//              are available to this living creature. This includes the actual
//              maxHitPoints value plus any bonuses as applied through
//              inventory elements or ancillary things such as guilds, race,
//              traits, research, background, and biological influences.
//
// Returns: the total maximum number of hit points available to this object
//-----------------------------------------------------------------------------
public nomask int maxHitPoints()
{
    int ret = 0;
    if (member(combatCache, "max hit points"))
    {
        ret = combatCache["max hit points"];
    }
    else
    {
        if (!maxHitPoints)
        {
            maxHitPoints = 30;
        }
        ret = maxHitPoints;

        object inventory = getModule("inventory");
        if (inventory)
        {
            ret += inventory->inventoryGetModifier("combatModifiers",
                "bonus hit points");
        }

        ret += calculateServiceBonuses("MaxHitPoints");

        object attributes = getModule("attributes");
        if (attributes)
        {
            ret += attributes->Con() * 6;
        }

        // This case will never happen with properly cloned living things. However,
        // the improperly done is possible. This removes the chance for division by
        // zero.
        if (ret < 1)
        {
            ret = 1;
        }
        combatCache["max hit points"] = ret;
    }

    return ret;
}

//-----------------------------------------------------------------------------
// Method: hitPoints
// Description: This method returns the current hit points available to this
//              living object. If the optional increase parameter is passed,
//              the hitPoints will be increased by that amount and an
//              onHitPointsChanged event will be broadcast. It is important to
//              note that hit points can only be increased via this method and
//              all hit point decreases MUST be accomplished through the hit()
//              method as this applies resistences and the like - the only
//              exception to this rule is research items.
//
// Parameters: increase - the optional increase in hit points
//
// Returns: the total number of hit points available to this object
//-----------------------------------------------------------------------------
public nomask varargs int hitPoints(int increase)
{
    // hitPoints can ONLY be removed via the hit method
    if(intp(increase) && ((increase > 0) || (previous_object() && 
       (member(inherit_list(previous_object()), 
       "/lib/modules/research/researchItem.c") > -1) && (abs(increase) <= hitPoints))))
    {
        hitPoints += increase;
        combatNotification("onHitPointsChanged");
    }

    if (hitPoints > maxHitPoints())
    {
        hitPoints = maxHitPoints();
    }
    return hitPoints;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string healthDescription()
{
    string ret = 0;
    if (hitPoints() < (maxHitPoints() / 16))
    {
        ret = "is knocking on death's door.";
    }
    else if (hitPoints() < (maxHitPoints() / 8))
    {
        ret = "is severely injured.";
    }
    else if (hitPoints() < (maxHitPoints() / 4))
    {
        ret = "has taken a beating.";
    }
    else if (hitPoints() < (maxHitPoints() / 2))
    {
        ret = "has been roughed up.";
    }
    else if (hitPoints() < (3 * maxHitPoints() / 4))
    {
        ret = "has some minor injuries.";
    }
    else if (hitPoints() < (7 * maxHitPoints() / 8))
    {
        ret = "is barely inured.";
    }
    else
    {
        ret = "is in good shape.";
    }

    return ret;
}

//-----------------------------------------------------------------------------
// Method: maxSpellPoints
// Description: This method returns the effective total maximum spell points
//              that are available to this living creature. This includes the 
//              actual maxSpellPoints value plus any bonuses as applied
//              through inventory elements or ancillary things such as guilds,
//              race, traits, research, background, and biological influences.
//
// Returns: the total maximum number of spell points available to this object
//-----------------------------------------------------------------------------
public nomask int maxSpellPoints()
{
    int ret = 0;

    if (member(combatCache, "max spell points"))
    {
        ret = combatCache["max spell points"];
    }
    else
    {
        if (!maxSpellPoints)
        {
            maxSpellPoints = 30;
        }
        ret = maxSpellPoints;

        object inventory = getModule("inventory");
        if (inventory)
        {
            ret += inventory->inventoryGetModifier("combatModifiers",
                "bonus spell points");
        }

        ret += calculateServiceBonuses("MaxSpellPoints");

        object attributes = getModule("attributes");
        if (attributes)
        {
            ret += (attributes->Int() * 3) + (attributes->Wis() * 3);
        }
        if (ret < 0)
        {
            ret = 0;
        }
        combatCache["max spell points"] = ret;
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: spellPoints
// Description: This method returns the current spell points available to this
//              living object. If the optional increase parameter is passed,
//              the spellPoints will be modified by that amount and an
//              onSpellPointsChanged event will be broadcast.
//
// Parameters: increase - the optional change in spell points
//
// Returns: the total number of spell points available to this object
//-----------------------------------------------------------------------------
public nomask varargs int spellPoints(int increase)
{
    if(intp(increase) && (increase != 0))
    {
        object inventory = getModule("inventory");
        if(increase > 0)
        {
            if(inventory)
            {
                increase += inventory->inventoryGetModifier("guildModifiers",
                    "bonus recover spell points");
            }
            
            increase += calculateServiceBonuses("RecoverSpellPoints");
        }
        else
        {
            if(inventory)
            {
                increase += inventory->inventoryGetModifier("guildModifiers",
                    "bonus reduce spell points");
            }
            
            increase += calculateServiceBonuses("ReduceSpellPoints");
            if (increase > 0)
            {
                increase = 0;
            }
        }
        spellPoints += increase;
        
        combatNotification("onSpellPointsChanged");
    }

    if(spellPoints > maxSpellPoints())
    {
        spellPoints = maxSpellPoints();
    }
    else if (spellPoints < 0)
    {
        spellPoints = 0;
    }

    return spellPoints;
}

//-----------------------------------------------------------------------------
// Method: maxStaminaPoints
// Description: This method returns the effective total maximum stamina points
//              that are available to this living creature. This includes the 
//              actual maxStaminaPoints value plus any bonuses as applied
//              through inventory elements or ancillary things such as guilds,
//              race, traits, research, background, and biological influences.
//
// Returns: the total maximum number of stamina points available to this object
//-----------------------------------------------------------------------------
public nomask int maxStaminaPoints()
{
    int ret = 0;

    if (member(combatCache, "max stamina points"))
    {
        ret = combatCache["max stamina points"];
    }
    else
    {
        if (!maxStaminaPoints)
        {
            maxStaminaPoints = 30;
        }
        ret = maxStaminaPoints;

        object inventory = getModule("inventory");
        if (inventory)
        {
            ret += inventory->inventoryGetModifier("combatModifiers",
                "bonus stamina points");
        }

        ret += calculateServiceBonuses("MaxStaminaPoints");

        object attributes = getModule("attributes");
        if (attributes)
        {
            ret += (attributes->Str() * 3) + (attributes->Con() * 3);
        }

        if (ret < 0)
        {
            ret = 0;
        }
        combatCache["max stamina points"] = ret;
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: staminaPoints
// Description: This method returns the current stamina points available to
//              this living object. If the optional increase parameter is 
//              passed, the staminaPoints will be modified by that amount and
//              an onStaminaPointsChanged event will be broadcast.
//
// Parameters: increase - the optional change in stamina points
//
// Returns: the total number of stamina points available to this object
//-----------------------------------------------------------------------------
public nomask varargs int staminaPoints(int increase)
{
    if(intp(increase) && (increase != 0))
    {
        object inventory = getModule("inventory");
        if(increase > 0)
        {
            if(inventory)
            {
                increase += inventory->inventoryGetModifier("guildModifiers",
                    "bonus recover stamina points");
            }
            
            increase += calculateServiceBonuses("RecoverStaminaPoints");
        }
        else
        {
            if(inventory)
            {
                increase += inventory->inventoryGetModifier("guildModifiers",
                    "bonus reduce stamina points");
            }
            
            increase += calculateServiceBonuses("ReduceStaminaPoints");
            if (increase > 0)
            {
                increase = 0;
            }
        }    
        staminaPoints += increase;
        combatNotification("onStaminaPointsChanged");       
    }
    if (staminaPoints > maxStaminaPoints())
    {
        staminaPoints = maxStaminaPoints();
    }
    else if (staminaPoints < 0)
    {
        staminaPoints = 0;
    }
    return staminaPoints;
}

//-----------------------------------------------------------------------------
// Method: calculateDefendAttack
// Description: This monstrosity of a method will determine this object's
//              ability to defend against attacks that occur during combat. It
//              is not intended to handle the ability to resist an attack,
//              reduce damage, or things of that nature - nor is it used to
//              determine defense against spells and special guild/race/trait/
//              research abilities, but only determine the ability to avoid an
//              attack from landing. It does check inventory/equipment
//              modifiers and apply parry, shield, and equipment bonuses, any
//              penalties/bonuses to dodging that armor might incur, and apply
//              bonuses from guild, race, traits, research, etc. This method is
//              not shadowable or in any way overridable. In order to modify
//              this result via a shadow or some other method, the
//              magicalDefendAttackBonus() method must be either shadowed or
//              overridden. In all likelihood, this should never be needed as
//              the inventory options provide a more than sufficient means of
//              handling this and the shadow should ONLY be used if other 
//              ancillary activities are being done.
//
// Returns: the overall defend attack value
//-----------------------------------------------------------------------------
public nomask int calculateDefendAttack()
{
    int ret = 0;
    object skills = getModule("skills");

    if (member(combatCache, "defend attack"))
    {
        ret += combatCache["defend attack"];
    }
    else
    {
        object inventory = getModule("inventory");

        if (inventory)
        {
            ret += inventory->inventoryGetDefendAttackBonus() -
                inventory->inventoryGetEncumberance();

            object primary = inventory->equipmentInSlot("wielded primary");
            if (inventory->isEquipped(primary) && skills)
            {
                string weaponType = primary->query("weapon type");
                if (weaponType)
                {
                    ret += (skills->getSkillModifier(weaponType) > 0) ? skills->getSkillModifier(weaponType) / 4 : 0;
                }
            }

            object offhand = inventory->equipmentInSlot("wielded offhand");
            if (inventory->isEquipped(offhand) && skills)
            {
                string weaponType = offhand->query("weapon type");
                // Give a bonus for one's shield skill if using a shield
                if (weaponType && (weaponType == "shield"))
                {
                    ret += (skills->getSkillModifier(weaponType) > 0) ? skills->getSkillModifier(weaponType) : 0;
                }
                else if (weaponType)
                {
                    ret += (skills->getSkillModifier(weaponType) > 0) ? skills->getSkillModifier(weaponType) / 4 : 0;
                }
            }

            // Apply the armor skill bonus
            object armor = inventory->equipmentInSlot("armor");
            if (armor && skills)
            {
                string armorType = armor->query("armor type");

                if (armorType && stringp(armorType))
                {
                    ret += skills->getSkillModifier(armorType) -
                        armor->query("skill penalty");
                }
            }

            if (inventory->inventoryGetModifier("combatModifiers", "disease"))
            {
                ret = to_int(ret * 0.9);
            }
        }

        ret += calculateServiceBonuses("DefendAttackBonus");

        object attributes = getModule("attributes");
        if (attributes)
        {
            ret += (attributes->dexterityBonus() / 2) +
                (attributes->wisdomBonus() / 2);
        }

        combatCache["defend attack"] = ret;
    }
    ret += this_object()->magicalDefendAttackBonus();

    object traits = getModule("traits");

    if (traits && traits->hasTraitOfRoot("offensive stance"))
    {
        ret = to_int(ret * 0.5);
    }
    else if (traits && traits->hasTraitOfRoot("defensive stance"))
    {
        ret = to_int(ret * 1.5);
    }

    object materialAttributes = getModule("materialAttributes");
    if (materialAttributes && skills && !materialAttributes->canSee())
    {
        if (!member(combatCache, "defend attack blind"))
        {
            combatCache["defend attack blind"] =
                skills->getSkillModifier("blind fighting") - 10;
        }
        ret += combatCache["defend attack blind"];
    }

    return ret;
}

//-----------------------------------------------------------------------------
// Method: calculateAttack
// Description: This monstrosity of a method will determine this object's
//              ability to successfully attack during combat. It is not 
//              intended to handle the ability to do damage during an attack,
//              increase damage, or things of that nature (those are handled in
//              calculateSoakDamage) - nor is it used to determine attack
//              for spells and special guild/race/trait/ research abilities,
//              but only determine the ability to land an attack. It does check
//              inventory/equipment modifiers and apply weapon skills and 
//              equipment bonuses, any penalties/bonuses that armor might 
//              incur, and apply bonuses from guild, race, traits, research.
//              It will decrease the attack by the passed in opponent's
//              calculateDefendAttack result. This method is not shadowable or
//              in any way overridable. In order to modify this result via a
//              shadow or some other method, the magicalAttackBonus() method
//              must be either shadowed or overridden. In all likelihood, this
//              should never be needed as the inventory options provide a more
//              than sufficient means of handling this and the shadow should
//              ONLY be used if other ancillary activities are being done.
//
// Parameters: attacker - this object's opponent.
//             weapon - the weapon used for this attack.
//
// Returns: the overall attack value
//-----------------------------------------------------------------------------
public nomask varargs int calculateAttack(object attacker, object weapon, int doNotRandomize) 
{
    int toHit = this_object()->magicalAttackBonus();

    if(attacker && objectp(attacker) && 
       function_exists("calculateDefendAttack", attacker))
    {
        toHit -= attacker->calculateDefendAttack();
    }

    object inventory = getModule("inventory");
    string attackKey = sprintf("attack %s", object_name(weapon));
    if (member(combatCache, attackKey))
    {
        toHit += combatCache[attackKey];
    }
    else
    {
        object skills = getModule("skills");
        toHit -= inventory->inventoryGetEncumberance();

        if(inventory->isEquipped(weapon))
        {
            toHit += inventory->inventoryGetAttackBonus(weapon);
        }
        else if(weapon && !inventory->isEquipment(weapon) &&
            attackObject()->isAttack(weapon))
        {
            // This is a special case - weapon is an AttackType
            toHit += weapon->attackTypeCalculateAttack();
        }

        if (inventory->inventoryGetModifier("combatModifiers", "poison"))
        {
            toHit = to_int(toHit * 0.8);
        }
        if(inventory->inventoryGetModifier("combatModifiers", "disease"))
        {
            toHit = to_int(toHit * 0.9);
        } 
        if(inventory->inventoryGetModifier("combatModifiers", "enfeebled"))
        {
            toHit = to_int(toHit * 0.85);
        }
        if(inventory->inventoryGetModifier("combatModifiers", "fortified"))
        {
            toHit = to_int(toHit * 1.15);
        }

        toHit += calculateServiceBonuses("AttackBonus");

        object materialAttributes = getModule("materialAttributes");
        if (materialAttributes && skills && !materialAttributes->canSee())
        {
            toHit += skills->getSkillModifier("blind fighting") - 10;
        }

        object attributes = getModule("attributes");
        if(attributes)
        {
            toHit += (attributes->dexterityBonus() / 2) +
                     (attributes->intelligenceBonus() / 2);
        }
        combatCache[attackKey] = toHit;
    }

    object traits = getModule("traits");
    if (traits && traits->hasTraitOfRoot("offensive stance"))
    {
        toHit = to_int(toHit * 1.5);
    }
    else if (traits && traits->hasTraitOfRoot("defensive stance"))
    {
        toHit = to_int(toHit * 0.5);
    }

    if (!doNotRandomize)
    {
        toHit += random(101) - 25;
    }

    return ((toHit < -100) ? -101 : toHit);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int calculateSoakDamage(string damageType)
{
   int ret = 0;
    object inventory = getModule("inventory");
       
    string soakKey = sprintf("soak %s", damageType);
    if (member(combatCache, soakKey))
    {
        ret += combatCache[soakKey];
    }
    else
    {
        ret += inventory->inventoryGetDefenseBonus(damageType);
        ret += calculateServiceBonuses("DefenseBonus");

        object attributes = getModule("attributes");
        if (attributes)
        {
            ret += (attributes->constitutionBonus() / 2) +
                (attributes->strengthBonus() / 2);
        }
        combatCache[soakKey] = ret;
    }

    if (inventory->inventoryGetModifier("combatModifiers", "paralysis"))
    {
        ret = to_int(ret * 0.9);
    }
    if (inventory->inventoryGetModifier("combatModifiers", "poison"))
    {
        ret = to_int(ret * 0.8);
    }

    ret += this_object()->magicalDefenseBonus();
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int calculateDamage(object weapon, string damageType, 
    int doNotRandomize)
{
    int ret = 0;
    
    object inventory = getModule("inventory");
    string damageKey = sprintf("damage %s for %s", damageType, 
        object_name(weapon));

    if (member(combatCache, damageKey))
    {
        ret += combatCache[damageKey];
    }
    else
    {
        if (attackObject()->isAttack(weapon))
        {
            ret += weapon->attackTypeCalculateDamage(this_object());
        }

        ret += inventory->inventoryGetDamageBonus(weapon, damageType);

        ret += calculateServiceBonuses("DamageBonus");

        object attributes = getModule("attributes");
        if (attributes)
        {
            if ((damageType == "physical") || attackObject()->isAttack(weapon))
            {
                ret += attributes->strengthBonus() / 2;
            }
            if (ret)
            {
                ret += (attributes->intelligenceBonus() / 4) +
                    (attributes->wisdomBonus() / 4);
            }
        }
        combatCache[damageKey] = ret;
    }

    if (inventory->inventoryGetModifier("combatModifiers", "enfeebled"))
    {
        ret = to_int(ret * 0.75);
    }
    if (inventory->inventoryGetModifier("combatModifiers", "fortified"))
    {
        ret = to_int(ret * 1.25);
    }

    ret += this_object()->magicalDamageBonus();

    if (!doNotRandomize)
    {
        ret += to_int((ret / 8.0) - random(ret / 4));
    }

    if (ret < 0)
    {
        ret = 0;
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isParalyzed()
{
    int ret = 0;
    
    object inventory = getModule("inventory");

    if(inventory)
    {
        ret = inventory->inventoryGetModifier("combatModifiers", "paralysis");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int magicalDefendAttackBonus()
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public int magicalAttackBonus()
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public int magicalDefenseBonus()
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public int magicalDamageBonus()
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void attackFumble()
{
    // Currently, we don't do this
}

/////////////////////////////////////////////////////////////////////////////
protected nomask float damageModifierFromAttack(int toHit)
{
    float retVal = 0.0;
    
    switch(toHit) 
    {
        // Really bad miss
        case -101: 
        {
            attackFumble();
            break;
        }
        // Missed
        case -100..10: 
        {
            retVal = 0.0;
            break;
        }

        // Standard hit
        case 11..95: 
        {
            retVal = 1.0;
            break;
        }

        // Slight critical
        case 96..135: 
        {
            retVal = 1.1;
            break;
        }

        // Moderate critical
        case 136..150: 
        {
            retVal = 1.25;
            break;
        }

        // Solid critical
        case 151..200: 
        {
            retVal = 1.5;
            break;
        }

        // Amazing attack
        default: 
        {
            retVal = 2.0;
            break;
        }
    }
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int addAttack(string attackToAdd, int damage, int toHit)
{
    int ret = 0;

    if(attackToAdd && damage)
    {
        mapping newAttack = ([
            "attack type": attackToAdd,
            "to hit": toHit,
            "damage": damage
        ]);
        
        if(attackObject()->isValidAttack(newAttack))
        {
            attacks += ({ newAttack });
            ret = 1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void clearAttacks()
{
    attacks = ({ });
    m_delete(combatCache, "attacks");
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs mapping *getWeaponAttacksFromBonus(int numAttacks, int addOffhand)
{
    mapping *attacksToReturn = ({});

    object inventory = getModule("inventory");
    if (inventory)
    {
        int hasOffhandWeapon = objectp(inventory->equipmentInSlot("wielded offhand")) &&
            (inventory->equipmentInSlot("wielded offhand") != 
            inventory->equipmentInSlot("wielded primary"));

        for (int i = 0; i < numAttacks; i++)
        {
            attacksToReturn += ({ (["attack type":"wielded primary"]) });

            if (hasOffhandWeapon && ((i % 2) || addOffhand))
            {
                attacksToReturn += ({ (["attack type":"wielded offhand"]) });
            }
        }
    }
    return attacksToReturn;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *getAttacks()
{
    mapping *attacksToReturn = ({});

    if (member(combatCache, "attacks"))
    {
        attacksToReturn += combatCache["attacks"];
    }
    else
    {
        int allowOnlyOneAttack = 0;
        attacksToReturn = attacks;
        object inventory = getModule("inventory");

        object weapon = inventory->equipmentInSlot("wielded primary");
        if (weapon)
        {
            allowOnlyOneAttack = (weapon->query("type") == "instrument");

            attacksToReturn += ({ (["attack type":"wielded primary"]) });
        }

        if (!allowOnlyOneAttack)
        {
            object offhand = inventory->equipmentInSlot("wielded offhand");

            // Don't add attacks for defense-only shields.
            if (offhand && offhand->query("weapon class") &&
                (offhand != inventory->equipmentInSlot("wielded primary")))
            {
                attacksToReturn += ({ (["attack type":"wielded offhand"]) });
            }

            if (!sizeof(attacksToReturn))
            {
                attacksToReturn += ({ ([
                    "attack type":"unarmed",
                    "to hit" : 50,
                    "damage" : 10
                ]) });
            }

            // Add attacks from external sources
            string *servicesToCheck = ({ "races", "guilds", "research", "traits", "background" });
            int addOffhandWeapon = 0;

            foreach(string serviceToCheck in servicesToCheck)
            {
                object service = getModule(serviceToCheck);
                if (service)
                {
                    mapping *extraAttacks =
                        call_other(service, sprintf("%sExtraAttacks", serviceToCheck));

                    if (sizeof(extraAttacks))
                    {
                        foreach(mapping extraAttack in extraAttacks)
                        {
                            if (attackObject()->isWeaponAttack(extraAttack))
                            {
                                attacksToReturn += getWeaponAttacksFromBonus(1, addOffhandWeapon % 2);
                                addOffhandWeapon++;
                            }
                            else if (attackObject()->isValidAttack(extraAttack))
                            {
                                attacksToReturn += ({ extraAttack });
                            }
                        }
                    }
                }
            }
        }

        object *modifiers = inventory->registeredInventoryObjects();

        if (modifiers && pointerp(modifiers) && sizeof(modifiers))
        {
            object attacksDictionary = getDictionary("attacks");
            if (attacksDictionary && function_exists("validAttackTypes",
                attacksDictionary))
            {
                string *attackList = attacksDictionary->validAttackTypes();

                foreach(object modifier in modifiers)
                {
                    foreach(string attack in attackList)
                    {
                        if (modifier->query(sprintf("bonus %s attack", attack)))
                            attacksToReturn += ({ (["attack type": attack,
                                "to hit" : 50 + modifier->query(sprintf("bonus %s attack", attack)),
                                "damage" : modifier->query(sprintf("bonus %s attack", attack))
                        ]) });
                    }
                    if (modifier->query("bonus weapon attack") && 
                        inventory->equipmentInSlot("wielded primary") &&
                        !allowOnlyOneAttack)
                    {
                        int numAttacks = modifier->query("bonus weapon attack");
                        attacksToReturn += getWeaponAttacksFromBonus(numAttacks);
                    }
                }
            }
        }
        combatCache["attacks"] = attacksToReturn;
    }
    return attacksToReturn + ({ });
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs object getTargetToAttack(int doNotRandomize)
{
    object attacker = 0;
    
    object *listOfPotentialAttackers = sort_array(filter(m_indices(hostileList),
            (: present($1, environment(this_object())) :)),
            (: hostileList[$1]["time"] > hostileList[$2]["time"] :));
    
    int numPotentialAttackers = sizeof(listOfPotentialAttackers);
    if(numPotentialAttackers)
    {        
        if (hostileList[listOfPotentialAttackers[0]]["time"] == 1)
        {
            attacker = listOfPotentialAttackers[0];
        }
        else
        {
            attacker = listOfPotentialAttackers[0];
            if (attacker && objectp(attacker) && !doNotRandomize &&
                ((random(101) + attacker->calculateDefendAttack()) > 50))
            {
                attacker = listOfPotentialAttackers[random(numPotentialAttackers)];
            }
        }
    }
    return attacker;    
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getHostileList()
{
    string ret = "Nothing at all, aren't you lucky?";

    object *attackers = m_indices(hostileList);
    if(sizeof(attackers))
    {
        ret = "";
        foreach(object attacker in attackers)
        {
            if (ret != "")
            {
                ret += ", ";
            }
            ret += capitalize(attacker->RealName());
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int unregisterAttacker(object attacker)
{
    int ret = 0;
    if (member(hostileList, attacker))
    {
        ret = 1;
        m_delete(hostileList, attacker);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void stopFight(object attacker)
{
    if (attacker && objectp(attacker))
    {
        unregisterAttacker(attacker);
        attacker->unregisterAttacker(this_object());
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int onKillList()
{
    int ret = 1;

    object player = getModule("player");
    object npc = getModule("npc");
    object henchman = getModule("henchman");

    if (player)
    {
        ret = onKillList;
    }
    else if(npc)
    {
        ret = npc->canAttack(this_player());
    }
    else if (henchman)
    {
        ret = henchman->canAttack(this_player());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void toggleKillList()
{
    object player = getModule("player");
    if (player)
    {
        onKillList = !onKillList;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void configurePVPSetting()
{
    object player = getModule("player");
    if (player &&!onKillList)
    {
        tell_object(player, sprintf("You can now engage in player vs. player "
            "combat outside of the arena.\n"));
        onKillList = 1;
    }
    else if(player)
    {
        tell_object(player, sprintf("You can not remove yourself from the "
            "player vs. player kill list.\n"));
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkKillList(object foe)
{
    int ret = onKillList() && foe->onKillList();

    if (!ret)
    {
        printf("You're not allowed to attack players not on the list!\n");
        foe->stopFight(this_object());
        stopFight(foe);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs int hitIsAllowed(object foe)
{
    int ret = living(this_object()) && environment() &&
        !this_object()->isDead() && !this_object()->isInvulnerable() &&
        !environment()->violenceIsProhibited() && 
        (!foe || present(foe, environment()));

    object player = getModule("player");
    if (player)
    {
        //        ret &&= query_ip_number(this_object());
    }
    if (ret && foe && objectp(foe))
    {
        if (function_exists("isDead", foe))
        {
            ret &&= !foe->isDead();
        }
        if (function_exists("isNPC", foe) &&
            !foe->isNPC())
        {
            ret &&= checkKillList(foe);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int inCombat()
{
    int ret = 0;

    if (sizeof(hostileList) && getTargetToAttack())
    {
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isInCombatWith(object attacker)
{
    return member(hostileList, attacker);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int registerAttacker(object attacker)
{
    int ret = hitIsAllowed(attacker);
    if (ret && !member(hostileList, attacker) && attacker->has("combat"))
    {
        hostileList[attacker] = (["time": time() + sizeof(hostileList) ]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int supercedeAttackers(object attacker)
{
    int ret = hitIsAllowed(attacker);

    if (ret && attacker->has("combat"))
    {
        hostileList[attacker] = ([ "time": 1 ]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int abortCombat(object attacker)
{
    int ret = !hitIsAllowed(attacker) || spellAction();
    
    if(combatDelay)
    {
        combatNotification("onCombatDelayed");
        combatDelay--;
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int isDead()
{
    int ret = 0;

    object materialAttributes = getModule("materialAttributes");
    if (materialAttributes)
    {
        ret = materialAttributes->Ghost();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void generateCombatStatistics(object foe)
{
    if(foe && function_exists("has", foe) &&
        foe->has("materialAttributes") && getModule("player") &&
        function_exists("saveCombatStatistics", this_object()))
    {
        getModule("player")->saveCombatStatistics(this_object(), foe);
    }            
}

/////////////////////////////////////////////////////////////////////////////
private nomask void generateCorpse(object murderer)
{
    object materialAttributes = getModule("materialAttributes");
    if(materialAttributes)
    {
        materialAttributes->Ghost(1);
        object corpse = clone_object("/lib/items/corpse.c");
        if(corpse)
        {
            corpse->corpseSetup(this_object());

            if(function_exists("isRealizationOfPlayer", murderer) &&
               function_exists("isRealizationOfPlayer", this_object()))
            {
                corpse->set("killed by player", murderer->RealName());
            }

            move_object(corpse, environment(this_object()));
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void updateFactionDispositionsFromCombat(object murderer)
{
    object factionService = getModule("factions");
    if (factionService && murderer && objectp(murderer))
    {
        int reputationPenalty;
        if (function_exists("effectiveLevel", this_object()))
        {
            int levelDisparity = this_object()->effectiveLevel() -
                murderer->effectiveLevel();

            reputationPenalty = 0 - ((levelDisparity > 1) ? levelDisparity : 1);
        }
        else
        {
            reputationPenalty = -1;
        }

        string *factionList = factionService->Factions();

        foreach(string faction in factionList)
        {
            murderer->updateFactionDisposition(faction, reputationPenalty, 1);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask int finishOffThisPoorDeadBastard(object murderer)
{
    int ret = 1;

    object player = getModule("player");
    if(player)
    {
        object persistence = getModule("/secure/persistence");
        if (persistence)
        {
            persistence->save();
        }
        object logger = getDictionary("log");
        if(logger)
        {
            logger->logDeath(player, murderer);
        }
    }
    
    if(murderer && function_exists("generateCombatStatistics", murderer))
    {
        murderer->generateCombatStatistics(this_object());
    }
    
    if(this_object() && function_exists("secondLife", this_object()))
    {
        ret = !this_object()->secondLife();
    }

    if (ret)
    {
        generateCorpse(murderer);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int determineFateFromDeath(object murderer)
{
    int killMe = 0;
    
    string colorConfiguration = this_object()->colorConfiguration() ?
        this_object()->colorConfiguration() : "none";

    if(!isDead())
    {

        object wizard = getModule("wizard");
        if(wizard)
        {
            tell_object(wizard, getDictionary("configuration")->decorate(
                "Your wizardhood protects you from death.\n",
                "death", "combat", colorConfiguration)); 
        }
        else if(environment() && 
                function_exists("suppressDeath", environment()))
        {
            string notDeadMessage = environment()->suppressDeath();

            if (notDeadMessage)
            {
                object attacker;
                while (attacker = getTargetToAttack())
                {
                    stopFight(attacker);
                }

                tell_object(this_object(), 
                    getDictionary("configuration")->decorate(
                    notDeadMessage, "death", "combat", colorConfiguration));
            }
            else
            {
                // Room didn't save this poor sot.
                killMe = 1;
            }
        }

        else
        {
            killMe = 1;
        }
    }
    
    if(killMe)
    {
        object player = getModule("player");
        if (player)
        {
            object attacker;
            while (attacker = getTargetToAttack())
            {
                stopFight(attacker);
            }

            tell_object(this_object(),
                getDictionary("configuration")->decorate("\nYou die.\nYou "
                    "have a strange feeling.\nYou can see your own dead "
                    "body from above.\n\n",
                    "death", "combat", colorConfiguration));
        }
        combatNotification("onDeath", 1, 1);
        updateFactionDispositionsFromCombat(murderer);
        killMe = finishOffThisPoorDeadBastard(murderer);
    }
    return killMe;
}
  
/////////////////////////////////////////////////////////////////////////////
private nomask int canBeHitIfEthereal(string damageType)
{
    int ret = 1;

    object traits = getModule("traits");
    if (traits && traits->hasTraitOfRoot("ethereal") &&
        (member(({ "electricity", "energy", "evil", "good", "fire",
            "magical" }), damageType) < 0))
    {
        ret = 0;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int calculateDamageResistance(int damage, string damageType)
{
    return to_int(damage *
        calculateServiceBonuses(sprintf("resist %s", damageType)) / 100.0);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void updateCombatSummary(object foe, int damageTaken,
    int hitsTaken, int damageInflicted, int hitsInflicted)
{
    if (member(({ "digest", "only vitals" }),
        this_object()->combatVerbosity()) > -1)
    {
        if (!member(combatSummaryDetails, foe))
        {
            combatSummaryDetails[foe] = ([
                "damage taken": damageTaken,
                "hits taken": hitsTaken,
                "damage inflicted": damageInflicted,
                "hits inflicted": hitsInflicted,
                "display time": time() + 10
            ]);
        }
        else
        {
            combatSummaryDetails[foe]["damage taken"] += damageTaken;
            combatSummaryDetails[foe]["hits taken"] += hitsTaken;
            combatSummaryDetails[foe]["damage inflicted"] += damageInflicted;
            combatSummaryDetails[foe]["hits inflicted"] += hitsInflicted;
        }

        if (time() >= combatSummaryDetails[foe]["display time"])
        {
            switch (this_object()->combatVerbosity())
            {
                case "digest":
                {
                    attackObject()->displayDigestMessage(this_object(), 
                        foe, combatSummaryDetails[foe]);
                    break;
                }
                case "only vitals":
                {
                    attackObject()->displayVitals(this_object(),
                        foe);
                    break;
                }
            }

            m_delete(combatSummaryDetails, foe);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int hit(int damage, string damageType, object foe)
{
    int ret = 0;

    if(!damageType)
    {
        damageType = "physical";
    }

    if(hitIsAllowed() && canBeHitIfEthereal(damageType))
    {
        if(!foe || !objectp(foe))
        {
            foe = previous_object();
        }
        registerAttacker(foe);
        // Make sure there's a heartbeat so that this can attack back
        set_heart_beat(1);

        int resistance = calculateDamageResistance(damage, damageType);
        ret = damage - calculateSoakDamage(damageType) - resistance;

        if(ret < 0)
        {
            ret = 0;
        }
        
        object traits = getModule("traits");
        if (traits && traits->hasTraitOfRoot("mana shield"))
        {
            int remainingDamage = ret - spellPoints;
            if (remainingDamage > 0)
            {
                ret = remainingDamage;
                spellPoints = 0;
            }
            else
            {
                spellPoints -= ret;
                ret = 0;
            }
        }

        if(ret > hitPoints)
        {
            ret = hitPoints;
        }

        updateCombatSummary(foe, 0, 0, ret, (ret > 0));

        if(ret && foe && function_exists("addExperience", foe) &&
            function_exists("getExperienceFromHit", this_object()))
        {
            call_direct(this_object(), "getExperienceFromHit", ret, foe);
        }

        hitPoints -= ret;
        combatNotification("onHit", ([ "type": damageType, 
                                       "damage": damage ]));
  
        if(hitPoints() <= 0)
        {
            determineFateFromDeath(foe);
        }
        
        object inventory = getModule("inventory");        
        if(foe && inventory)
        {
            int reflection = inventory->inventoryGetModifier("combatModifiers", 
                "damage reflection");
                
            if(reflection)
            {
                reflection = to_int(
                    (((reflection > 50) ? 50 : reflection) / 100.0) * damage);

                if (reflection > 1)
                {
                    object victim = getTargetToAttack();
                    if (objectp(victim))
                    {
                        updateCombatSummary(victim, reflection, 
                            (reflection > 0), 0, 0);

                        victim->hit(reflection, damageType, this_object());
                        attackObject()->displayMessage(this_object(), victim,
                            damage, attackObject()->getAttack("reflection"));
                    }
                }
            }
        }
    }
    if (isDead())
    {
        if(foe && objectp(foe))
        {
            attackObject()->displayDeathMessage(foe, this_object(),
                ret);
        }
        say(sprintf("%s died.\n", capitalize(this_object()->RealName())));
        getDictionary("combatChatter")->displayCombatChatter(ret,
            foe, this_object());

        if (!getModule("player"))
        {
            destruct(this_object());
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void doOneAttack(object foe, object weapon)
{
    int toHit = calculateAttack(foe, weapon);
    int damageInflicted = 0;
    int damage = 0;
    string primaryDamageType = "physical";
    float hitSucceeded = damageModifierFromAttack(toHit);
    
    if(weapon && objectp(weapon) && foe && objectp(foe))
    {
        if(weapon->getDamageType())
        {
            primaryDamageType = weapon->getDamageType();
        }

        if (foe->hasTraitOfRoot("ethereal") && !weapon->canDamageEthereal())
        {
            hitSucceeded = 0.0;
        }

        if((hitSucceeded > 0.0) && foe && objectp(foe))
        {
            object inventory = getModule("inventory");
            if(inventory && weapon && objectp(weapon) &&
                (inventory->isEquipped(weapon) || weapon->getDamageType()))
            {
                string *extraDmg = inventory->getExtraDamageTypes(weapon);
                if(extraDmg)
                {
                    foreach(string damageType in extraDmg)
                    {
                        damage = calculateDamage(weapon, damageType);

                        // foe can die / be destructed at any time - need to verify that it
                        // still exists
                        if(foe && objectp(foe))
                        {
                            damageInflicted += foe->hit(damage, damageType, this_object());
                        }
                    }
                }
            }

            damage = to_int(calculateDamage(weapon, primaryDamageType) * hitSucceeded);

            string extraHitFunction = weapon->query("hit method");
            if(stringp(extraHitFunction) && function_exists(extraHitFunction, weapon))
            {
                int extraDamage = call_other(weapon, extraHitFunction);
                if(intp(extraDamage))
                {
                    damage += extraDamage;
                }
            }

            if (roundsSinceAttack > 0)
            {
                damage = to_int(damage * (1 + (roundsSinceAttack / 10.0)));
            }

            // foe can die / be destructed at any time - need to verify that it
            // still exists
            if(foe && objectp(foe))
            {
                damageInflicted += foe->hit(damage, primaryDamageType, this_object());
            }
        }

        if(foe && objectp(foe))
        {
            getDictionary("combatChatter")->displayCombatChatter(damageInflicted, 
                this_object(), foe);

            updateCombatSummary(foe, damageInflicted, 
                (damageInflicted > 0), 0, 0);
            attackObject()->displayMessage(this_object(), foe, damageInflicted,
                weapon);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void registerAttack(object attacker, object foe, 
    int fireEvents)
{
    foe->registerAttacker(this_object());
    registerAttacker(foe);

    set_heart_beat(1);

    if (fireEvents)
    {
        combatNotification("onAttack");
        if (function_exists("notify", foe))
        {
            call_other(foe, "notify", "onAttacked");
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int roundsSinceLastAttack()
{
    return roundsSinceAttack;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void resetRoundsSinceLastAttack()
{
    roundsSinceAttack = 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int attack(object foe)
{
    int ret = 0;
    object traits = getModule("traits");

    if(abortCombat(foe))
    {
        if(foe)
        {
            stopFight(foe);
        }
    }
    else if ((roundsSinceAttack < 10) &&
        traits && traits->hasTraitOfRoot("do not attack"))
    {
        roundsSinceAttack++;
        registerAttack(this_object(), foe, 0);

        if (this_object()->combatVerbosity() == "show vitals")
        {
            attackObject()->displayVitals(this_object(), foe);
        }
    }
    else if(foe && objectp(foe))
    {
        registerAttack(this_object(), foe, 1);

        ret = 1;
        foreach(mapping attack in getAttacks())
        {
            if(attackObject()->isWeaponAttack(attack))
            {
                object inventory = getModule("inventory");
                if(inventory)
                {
                    object weapon = 
                        inventory->equipmentInSlot(attack["attack type"]);
                    if(!weapon)
                    {
                        weapon = attackObject()->getAttack("unarmed");
                    }
                    
                    if (weapon->query("type") == "instrument")
                    {
                        object song = attackObject()->getAttack("musical");
                        if (song && song->songIsQueued(this_object()))
                        {
                            song->playSong(this_object(), weapon, foe);
                        }
                    }
                    else
                    {
                        doOneAttack(foe, weapon);
                    }
                }                   
            }
            else if(attackObject()->isValidAttack(attack))
            {
                object weapon = attackObject()->getAttack(
                    attack["attack type"]);
                
                weapon->setAttackValues(attack["damage"], attack["to hit"]);                
                doOneAttack(foe, weapon);
            }
        }

        if (this_object()->combatVerbosity() == "show vitals")
        {
            attackObject()->displayVitals(this_object(), foe);
        }

        object persona = getModule("personas");
        if (objectp(persona) && objectp(foe))
        {
            persona->executePersonaResearch(foe->RealName());
        }
        roundsSinceAttack = 0;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
static void handleMoveFromCombat()
{
    if (getTargetToAttack())
    {
        spellAction(1);
        string colorConfiguration = this_object()->colorConfiguration() ?
            this_object()->colorConfiguration() : "none";

        tell_object(this_object(),
            getDictionary("configuration")->decorate("You have fled the scene "
                "of battle! Your enemies shan't forget you.\n",
                "flee", "combat", colorConfiguration));
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int Wimpy(string newWimpyVal, int suppressDisplay)
{
    if(!suppressDisplay && (!newWimpyVal || !stringp(newWimpyVal)))
    {
        printf("Wimpy: %d%%\n", wimpy);
    }
    else if (!suppressDisplay)
    {
        // Alas, to_int will return 0 if a string w/o an int is passed.
        wimpy = to_int(newWimpyVal);

        if(wimpy > 70)
        {
            wimpy = 70;
            printf("Valid wimpy values range from 0-70. ");
        }
        else if(wimpy < 0)
        {
            wimpy = 0;
            printf("Valid wimpy values range from 0-70. ");
        }
        printf("Wimpy set to: %d%%\n", wimpy);
    }
    return wimpy;
}

/////////////////////////////////////////////////////////////////////////////
static nomask int triggerWimpy()
{
    int ret = hitPoints() < to_int((maxHitPoints() * (wimpy / 100.0)));
    
    if(ret)
    {
        combatNotification("onRunAway");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int calculateVitalsHealRate(string vital)
{
    int ret = 0;
    object attributes = getModule("attributes");
    object inventory = getModule("inventory");

    if(vital && attributes)
    {
        switch(vital)
        {
            case "hit points":
            {
                if (member(combatCache, "heal hit points"))
                {
                    ret = combatCache["heal hit points"];
                }
                else
                {
                    ret = 1 + (attributes->Con() / 10) +
                        calculateServiceBonuses("BonusHealHitPoints") +
                        inventory->inventoryGetModifier("combatModifiers",
                            "bonus heal hit points");
                    combatCache["heal hit points"] = ret;
                }
                break;
            }
            case "spell points":
            {
                if (member(combatCache, "heal spell points"))
                {
                    ret = combatCache["heal spell points"];
                }
                else
                {
                    ret = 1 + ((attributes->Int() + attributes->Wis()) / 12) +
                        calculateServiceBonuses("BonusHealSpellPoints") +
                        inventory->inventoryGetModifier("combatModifiers",
                            "bonus heal spell points");
                    combatCache["heal spell points"] = ret;
                }
                break;
            }
            case "stamina":
            {
                if (member(combatCache, "heal stamina points"))
                {
                    ret = combatCache["heal stamina points"];
                }
                else
                {
                    ret = 1 + (attributes->Con() / 10) + (attributes->Dex() / 15) +
                        calculateServiceBonuses("BonusHealStamina") +
                        inventory->inventoryGetModifier("combatModifiers",
                            "bonus heal stamina");
                    combatCache["heal stamina points"] = ret;
                }
                break;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int calculateTimeToNextVitalsHeal(string vital)
{
    int ret = IntervalBetweenHealing;
    object attributes = getModule("attributes");
    object inventory = getModule("inventory");

    if(vital && stringp(vital) && attributes)
    {
        switch(vital)
        {
            case "hit points":
            {
                if (!member(combatCache, "heal hit points rate"))
                {
                    combatCache["heal hit points rate"] =
                        calculateServiceBonuses("BonusHealHitPointsRate") +
                        inventory->inventoryGetModifier("combatModifiers", 
                            "bonus heal hit points rate");
                }
                ret -= combatCache["heal hit points rate"];
                break;
            }
            case "spell points":
            {
                if (!member(combatCache, "heal spell points rate"))
                {
                    combatCache["heal spell points rate"] =
                        calculateServiceBonuses("BonusHealSpellPointsRate") +
                        inventory->inventoryGetModifier("combatModifiers",
                            "bonus heal spell points rate");
                }
                ret -= combatCache["heal spell points rate"];
                break;
            }
            case "stamina":
            {
                if (!member(combatCache, "heal stamina rate"))
                {
                    combatCache["heal stamina rate"] =
                        calculateServiceBonuses("BonusHealStaminaRate") +
                        inventory->inventoryGetModifier("combatModifiers",
                            "bonus heal stamina rate");
                }
                ret -= combatCache["heal stamina rate"];
                break;
            }
        }
    }
    if (ret < 4)
    {
        ret = 4;
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
static nomask void combatHeartBeat()
{
    if(spellAction > 0)
    {
        spellAction--;
    }

    object factions = getModule("factions");
    if(factions)
    {
        object *foes = factions->getAggressive(environment());
        if (foes)
        {
            foreach(object foe in foes)
            {
                if (foe && !member(hostileList, foe))
                {
                    hostileList[foe] = (["time": time()]);
                }
            }
        }
    }
    
    object inventory = getModule("inventory");
    object attacker = getTargetToAttack();

    if (this_object()->hasActiveCompositeResearch())
    {
        object instrument = inventory ?
            inventory->equipmentInSlot("wielded primary") : 0;

        object song = attackObject()->getAttack("musical");
        if (song && song->songIsQueued(this_object()))
        {
            song->playSong(this_object(), instrument);
        }

        if (sizeof(getAttacks()) > 1)
        {
            attack(attacker);
        }
    }
    if (inventory->inventoryGetModifier("combatModifiers", "poison"))
    {
        hit(5, "poison");
    }

    else if(attacker)
    {
        object chat = getModule("combatChatter");
        if(chat)
        {
            chat->combatChatterDisplayMessage();
        }
      
        object artificialIntelligence = getModule("artificialIntelligence");
        if(artificialIntelligence)
        {
            artificialIntelligence->aiCombatAction(getTargetToAttack());
        }

        int numberAttackRounds = 1;
        if(inventory)
        {
            numberAttackRounds -= 
                inventory->inventoryGetModifier("combatModifiers", "slow") % 2;
            if(!WasSlowedLastRound && !numberAttackRounds)
            {
                WasSlowedLastRound = 1;
            }
            else
            {
                numberAttackRounds = 1;
                WasSlowedLastRound = 0;
            }

            numberAttackRounds +=
                inventory->inventoryGetModifier("combatModifiers", "haste") ? 
                    1 : 0;


            if (inventory->inventoryGetModifier("combatModifiers", "paralysis"))
            {
                numberAttackRounds = 0;
            }
        }
        while(numberAttackRounds > 0)
        {
            attack(attacker);
            numberAttackRounds--;
        }

        object movement = getModule("movement");
        if(attacker && present(attacker) && triggerWimpy() && movement)
        {
            movement->runAway();
        }
    }
    else
    {
        combatSummaryDetails = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask void healingHeartBeat()
{
    if((timeToHealHP <= 0) && (hitPoints() < maxHitPoints()))
    {
        hitPoints(calculateVitalsHealRate("hit points"));
        timeToHealHP = calculateTimeToNextVitalsHeal("hit points");
    }
    else
    {
        timeToHealHP -= 2;
    }

    if((timeToHealSP <= 0) && (spellPoints() < maxSpellPoints()))
    {
        spellPoints(calculateVitalsHealRate("spell points"));
        timeToHealSP = calculateTimeToNextVitalsHeal("spell points");
    }
    else
    {
        timeToHealSP -= 2;
    }

    if((timeToHealST <= 0) && (staminaPoints() < maxStaminaPoints()))
    {
        staminaPoints(calculateVitalsHealRate("stamina"));
        timeToHealST = calculateTimeToNextVitalsHeal("stamina");
    }
    else
    {
        timeToHealST -= 2;
    }    
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs string vitalsDetails(string vital, object configuration,
    string colorConfiguration, string charset, int isConcise)
{
    int current = call_other(this_object(), lower_case(vital) + "Points");
    int max = call_other(this_object(), "max" + capitalize(vital) + "Points");

    if (current > max)
    {
        current = max;
    }

    string bar = "==========";
    string emptyBar = "";

    if (charset != "screen reader")
    {
        if (!max)
        {
            bar = "//////////";
        }
        else
        {
            bar[(10 * current) / max..] = "";
            for (int i = ((10 * current) / max); i < 10; i++)
            {
                emptyBar += ".";
            }
        }

        if (charset == "unicode")
        {
            bar = regreplace(bar, "=", "\u25ac", 1);
            emptyBar = regreplace(emptyBar, "[.]", "\u2237", 1);
        }
    }
    else
    {
        bar = sprintf("%3d%%      ", to_int(100 * (1.0 * current / max)));
    }

    string extra = (vital != "Stamina") ? " Points" : "";
    string label = "";
    if (isConcise)
    {
        label = configuration->decorate(sprintf("%2s: ", 
            (vital == "Stamina") ? "ST" : vital[0..0] + "P"),
            "content", "score", colorConfiguration);
    }
    else
    {
        label = configuration->decorate(sprintf("%12s: ", vital + extra),
            "content", "score", colorConfiguration);
    }

    return label + 
        configuration->decorate(sprintf("%s", bar),
            "bar", "score", colorConfiguration) +
        configuration->decorate(sprintf("%s ", emptyBar),
            "empty bar", "score", colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string vitals(string colorConfiguration, string charset)
{
    object settings = getModule("settings");
    if (objectp(settings) && !colorConfiguration)
    {
        colorConfiguration = settings->colorConfiguration() || "none";
    }
    if (objectp(settings) && !charset)
    {
        charset = settings->charsetConfiguration() || "ascii";
    }

    object configuration = getDictionary("configuration");
    object commandDictionary = getDictionary("commands");

    return commandDictionary->banneredContent(colorConfiguration, charset,
            vitalsDetails("Hit", configuration, colorConfiguration, charset) + 
            vitalsDetails("Spell", configuration, colorConfiguration, charset) +
            vitalsDetails("Stamina", configuration, colorConfiguration, charset)) +
        commandDictionary->banneredContent(colorConfiguration, charset,
            configuration->decorate(sprintf("%16d/%-5d", hitPoints(), 
                maxHitPoints()), "information", "score", colorConfiguration) +
            configuration->decorate(sprintf("%20d/%-5d", spellPoints(), 
                maxSpellPoints()), "information", "score", colorConfiguration) + 
            configuration->decorate(sprintf("%18d/%-8d", staminaPoints(), 
                maxStaminaPoints()), "information", "score", colorConfiguration));
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string singleLineVitals(string colorConfiguration, 
    string charset)
{
    object settings = getModule("settings");
    if (objectp(settings) && !colorConfiguration)
    {
        colorConfiguration = settings->colorConfiguration() || "none";
    }
    if (objectp(settings) && !charset)
    {
        charset = settings->charsetConfiguration() || "ascii";
    }

    object configuration = getDictionary("configuration");
    object commandDictionary = getDictionary("commands");

    return vitalsDetails("Hit", configuration, colorConfiguration, charset, 1) + 
           vitalsDetails("Spell", configuration, colorConfiguration, charset, 1) +
           vitalsDetails("Stamina", configuration, colorConfiguration, charset, 1);
}

/////////////////////////////////////////////////////////////////////////////
static nomask void resetCombatCache()
{
    combatCache = ([]);
    combatNotification("onRecalculating");

    call_out("maxHitPoints", 0);
    call_out("maxSpellPoints", 0);
    call_out("maxStaminaPoints", 0);
    call_out("calculateDefendAttack", 0);
}
