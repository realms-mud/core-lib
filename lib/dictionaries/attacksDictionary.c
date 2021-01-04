//*****************************************************************************
// Class: attacksDictionary
// File Name: attacksDictionary.c
//
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string WeaponBlueprint = "lib/items/weapon.c";
private string AttacksDir = "/lib/modules/combat/attacks";
private string AttackBlueprint = "lib/modules/combat/attacks/baseAttack.c";
private string MaterialAttributes = "lib/modules/materialAttributes.c";
private mapping attackObjects = ([]);
private object MessageParser = 0;

/////////////////////////////////////////////////////////////////////////////
private nomask object getAttackObject(string type)
{
    object ret = 0;
    if (member(attackObjects, type) &&
        objectp(attackObjects[type]))
    {
        ret = attackObjects[type];
    }
    else
    {
        attackObjects[type] = load_object(type);
        ret = attackObjects[type];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getAttack(string type)
{
    object ret = 0;

    if (!type || !stringp(type))
    {
        type = "physical";
    }

    string fileName = sprintf("%s/%sAttack.c", AttacksDir, type);
    if(file_size(fileName) > 0)
    {
        ret = getAttackObject(fileName);
    }
    return ret;
}

// attack MUST be of the following format:
// mapping attack = ([
//    "attack type": (attack types key),
//    "to hit": (integer used in toHit calculation),
//    "damage": (integer used in damage calculation)
/////////////////////////////////////////////////////////////////////////////
public nomask int isValidAttack(mapping attack)
{
    return (attack && mappingp(attack) &&
            member(attack, "attack type") &&
            stringp(attack["attack type"]) &&
            getAttack(attack["attack type"]) &&
            member(attack, "to hit") &&
            intp(attack["to hit"]) &&
            member(attack, "damage") &&
            intp(attack["damage"]));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isWeaponAttack(mapping attack)
{
    return (attack && mappingp(attack) &&
            member(attack, "attack type") &&
            (member(({ "weapon", "wielded primary", "wielded offhand"}),
                attack["attack type"]) > -1));
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping getAttackMapping(string attackType, int damage,
    int toHit)
{
    mapping ret = 0;
    if (attackType == "weapon")
    {
        ret = (["attack type":attackType]);
    }
    else if(getAttack(attackType))
    {
        ret = ([ "attack type": attackType ]);
        if(damage && intp(damage))
        {
            ret["damage"] = damage;
        }
        if(toHit && intp(toHit))
        {
            ret["to hit"] = toHit;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *validAttackTypes()
{
    string *ret = ({ });
    string *attackFiles = get_dir(sprintf("%s/*Attack.c", AttacksDir));
    attackFiles -= ({ AttackBlueprint });
    foreach(string attack in attackFiles)
    {
        object attackObj = getAttack(regreplace(attack, "Attack.c", ""));
        if(attackObj)
        {
            ret += ({ attackObj->getDamageType() });
        }
    }
    ret = m_indices(mkmapping(ret));
    return ret + ({ });
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isAttack(object potentialAttack)
{
    return (member(inherit_list(potentialAttack), AttackBlueprint) > -1);
}

/////////////////////////////////////////////////////////////////////////////
private nomask object messageParser()
{
    if (!objectp(MessageParser))
    {
        MessageParser = load_object("/lib/core/messageParser.c");
    }
    return MessageParser;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int isValidAttacker(object attacker)
{
    return (attacker && objectp(attacker) && 
            (member(inherit_list(attacker), MaterialAttributes) > -1));
}

/////////////////////////////////////////////////////////////////////////////
private nomask int isValidWeapon(object weapon)
{
    return (weapon && objectp(weapon) &&
           ((member(inherit_list(weapon), WeaponBlueprint) > -1) ||
            (member(inherit_list(weapon), AttackBlueprint) > -1)));
}

/////////////////////////////////////////////////////////////////////////////
private nomask object getDamageType(object weapon)
{
    object ret = 0;
    if(isValidWeapon(weapon))
    {
        if ((member(inherit_list(weapon), WeaponBlueprint) > -1))
        {
            string type = weapon->getDamageType();
            if (!type && sizeof(weapon->query("damage type")) > 0)
            {
                type = weapon->query("damage type")[0];
            }
            ret = getAttack(type);
        }
        else if(member(inherit_list(weapon), AttackBlueprint) > -1)
        {
            ret = weapon;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string parseTemplate(string template, string perspective,
                                    object attacker, object foe, object weapon)
{
    string message = template;
    // ##Infinitive::verb##
    // ##AttackerName## - Attacker's name
    // ##AttackerWeapon## - type of attacker's weapon (longsword, short sword,
    //   claymore...)
    // ##AttackerPossessive[::Name]## - Attacker possessive / your
    // ##AttackerObjective## - Attacker's objective / you
    // ##AttackerSubjective## - Attacker's subjective/pronoun / you
    // ##Target[NPOS]## - Target's (one of above 4)
    // ##HitDictionary## - random word from the hit dictionary (slash/slashes,
    //   chop/chops)
    // ##SimileDictionary## - random word from the simile dictionary
    // There's another special case for possessive:
    // ##[AT]P[::N]## - ##AP::N## -> "Bob's" or "your" for attacker named Bob
    //                  ##TP::N## -> "Bob's" or "your" for target named Bob

    // dictionary calls must be done first!
    object attackType = getDamageType(weapon);

    int isSecondPerson = (perspective == "attacker");
    if(isValidWeapon(weapon))
    {
        message = messageParser()->parseTargetWeapon(message, "Attacker",
            weapon);
    }
    if(attackType && objectp(attackType))
    {
        message = messageParser()->parseSimileDictionary(message, attackType);
        message = messageParser()->parseVerbDictionary(message, 
            "HitDictionary", attackType);

        message = messageParser()->parseVerbs(message, isSecondPerson);
        message = regreplace(message, "##ResponseInfinitive::([^#]+)##", "##Infinitive::\\1##", 1);
        message = messageParser()->parseVerbs(message, !isSecondPerson);
    }

    if(isValidAttacker(attacker))
    {
        message = messageParser()->parseTargetInfo(message, "Attacker", 
            attacker, isSecondPerson);
    }

    if(isValidAttacker(foe))
    {    
        isSecondPerson = (perspective == "defender");
        message = messageParser()->parseTargetInfo(message, "Target", 
            foe, isSecondPerson);      
    }

    message = messageParser()->capitalizeSentences(message);
    return message;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getColorForDamage(int damageInflicted)
{
    string ret;
    switch (damageInflicted)
    {
        case 0:
        {
            ret = "miss";
            break;
        }
        case 1..15:
        {
            ret = "light hit";
            break;
        }
        case 16..50:
        {
            ret = "hit";
            break;
        }
        case 51..100:
        {
            ret = "heavy hit";
            break;
        }
        default:
        {
            ret = "extreme hit";
            break;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void displayMessage(object attacker, object foe,
                                  int damageInflicted, object weapon)
{
    if(intp(damageInflicted) && weapon && objectp(weapon))
    {
        object damageType = getDamageType(weapon);
        
        if(damageType && objectp(damageType))
        {
            // This can only happen if damageType is of type baseAttack
            string template = damageType->getMessage(damageInflicted);

            if ((damageInflicted < 1) && foe->hasTraitOfRoot("ethereal"))
            {
                template = "##AttackerPossessive[::Name]## attack harmlessly "
                    "passes through ##TargetName##.";
            }
            else if ((damageInflicted < 1) && 
                (member(({ "physical", "slash", "bludgeon", "unarmed", "thrust" }),
                    damageType->getDamageType()) > -1))
            {
                int missType = random(51);
                int parryRange = foe->getSkill("parry");
                int dodgeRange = foe->getSkill("dodge") + parryRange;

                if ((missType <= parryRange) && !random(2))
                {
                    template = regreplace(template, "##Infinitive::miss##", 
                        "##TargetSubjective## ##ResponseInfinitive::parry## "
                        "the attack", 1);
                }
                else if (missType <= dodgeRange)
                {
                    template = regreplace(template, "##Infinitive::miss##", 
                        "##TargetSubjective## ##ResponseInfinitive::dodge## "
                        "the attack", 1);
                }
            }
            // This annoying loop handles the fact that everyone has different
            // setting for color.
            object *characters = filter(all_inventory(environment(attacker)),
                (: $1->isRealizationOfLiving() :));

            object configuration = getDictionary("configuration");

            string damageLevel = getColorForDamage(damageInflicted);

            foreach(object person in characters)
            {
                if(person && objectp(person))// && interactive(person))
                {
                    string message;
                    if(person == attacker)
                    {
                        message = parseTemplate(template, "attacker", attacker,
                                                foe, weapon);
                    }
                    else if(person == foe)
                    {
                        message = parseTemplate(template, "defender", attacker,
                                                foe, weapon);
                    }
                    else
                    {
                        message = parseTemplate(template, "other", attacker,
                                                foe, weapon);
                    }

                    if (damageInflicted)
                    {
                        message = format(message, 78);
                        
                        message = configuration->decorate(
                            message[0..sizeof(message) - 2],
                            damageLevel, "combat", person->colorConfiguration()) +
                            configuration->decorate(
                                sprintf(" [ %d ]\n", damageInflicted),
                                "damage", "combat", person->colorConfiguration());
                    }
                    else
                    {
                        message = configuration->decorate(format(message, 78),
                            "miss", "combat", person->colorConfiguration());
                    }
                    tell_object(person, message);
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidDamageType(string damageType)
{
    return (getAttack(damageType) != 0);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isOutOfRange(string damageType, int value)
{
    int ret = value < 1;
    object attack = getAttack(damageType);
    if(!ret && attack && objectp(attack) && function_exists("maxDamage", attack))
    {
        ret = value > attack->maxDamage();
    }
    return ret;
}
