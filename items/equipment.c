//*****************************************************************************
// Class: equipment
// File Name: equipment.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
// Description: This class defines exactly what equipment is and as such,
//              must be inherited by all equipment. 
//
//*****************************************************************************
virtual inherit "/lib/items/item.c";

#include "/lib/include/inventory.h"

private nosave string GuildsBlueprint = "/lib/dictionaries/guildsDictionary.c";
private nosave string RacesBlueprint = "/lib/dictionaries/racialDictionary.c";
private nosave string SkillsBlueprint = "/lib/dictionaries/skillsDictionary.c";
protected nosave string ItemTypesBlueprint = "/lib/dictionaries/materialsDictionary.c";

// This mapping shows all potential modifiers for a specified equipment piece.
// It is IMPORTANT to note that not all modifiers are available for all items
// and these cases are denoted by a tag - such as (ARMOR) for armor-only 
// components - at the end of a given comment
//protected mapping itemData = ([ 
//  "aliases": ({ }),  // string array of alternate names for item
//  "armor class":     // armor class applied to item (NOT the bonus) (ARMOR)
//  "bonus <thing>":   // attribute/hp/etc bonuses while equipped. Examples:
//  "bonus hit points": 20     // give 20 extra hit points while equipped
//  "bonus heal hit points": 3 // heal extra 3 hp per heart_beat heal interval
//  "bonus heal hit points rate": 2 // decrease heal (hp) interval by 2 seconds
//  "bonus strength": 2        // add 2 to the equipper's strength stat
//  "bonus longsword": 4       // add 4 to the longsword skill of the equipper
//  "bonus armor class": 2     // add 2 the the equipper's armor class  
//  "charges":         // number of charges the item has
//  "craftsmanship":   // The skill of the craftsman who created the item
//  "cursed": ([
//      "equip message":
//      "failed unequip message":
//  ]),
//  "defense class":   // Defense class of an item (NOT the bonus) (WEAPON)
//  "destruct method": // function existing in item that is called on destruct
//  "enchantments": ([ // adds damage of <key> type to attacks by user
//      "fire": 20     // an example that adds 20 fire damage while equipped
//  ]),                // see attacks.c for details
//  "encumberance":    // encumberance ABOVE/BELOW that applied by material or
                       // item type - see materials.c for details
//  "equip message":   // Message displayed when the item is equipped
//  "equip method":    // Method existing in item that is called on equipping
//  "equipment locations":  // Locations where this item can be equipped - 
                            // please see inventory.h for bit string
//  "hit method":      // function in item that is called on hit (WEAPON)
//  "identified":
//  "info":            // Special item information used by identify skill
//  "light": 1,        // the piece of equipment is a light source
//  "long":            // Item's long description - applied via parseDescription
//  "additional long": // Additional description displayed after identified
//  "material":        // Material the item is made out of - see materials.c
//  "name":            // The name of the item
//  "no steal":        // flag set to true if the item cannot be stolen
//  "no sell":         // flag set to true if the item cannot be sold
//  "owner":           // The name of the item's owner
//  "prerequisites": ([
//      "level": 10,    // The requirements for equipping this item
//      "race": "elf",  // levels, attributes, quests completed
//      "research": ([  // race, traits, and research are all valid keys
//          "use kirluin": 1,
//      ]),
//      "guilds": ([    // Only one of prohibited or allowed can be used
//          "prohibited": ({ }) // if set, these guilds cannot equip this
//          "allowed": ({ })    // if set, only the guilds in the array can use
//          "message":       // message displayed on failed equip
//      ]),
//      "quests": ([
//          "placate the trolls": 1,
//          "retrieve pencil": 1
//      ]),
//      "skills": ([       // Minumum skills needed to equip and use this item
//          "long sword": 5 // This is the modifier - not the raw skill!
//      ]),
//  ]),
//  "read message unidentified":// The message returned when the item is "read"
//  "read message identified":  // either while identified or unidentified
//  "register event handler":   // Set to true if this has events that must be
//                              // (un)registered when (un)equipped. Must created
//                              // an instance with the desired event handler
//  "resistances": ([  // adds protection from damage of <key> type
//      "fire": 10
//  ]),
//  "short":           // short description
//  "unequip message": // Message displayed when the item is unequipped
//  "unequip method":  // Method existing in item that is called on unequip
//  "value":           // Value / base buy cost of the item
//  "weapon class":    // The wc of the item ABOVE the material/type default
                       // Ex: a steel longsword with this value set at 3
                       // would have an effective wc of 14. (WEAPON)
//  "weight":          // weight of the item - separate from encumberance
//]);

private string *prohibitedKeys = ({ "armor class", "defense class", 
    "weapon class", "hit method", "armor type", "weapon type", "offhand" });
 
/////////////////////////////////////////////////////////////////////////////
protected nomask object materialsObject()
{
    return load_object(ItemTypesBlueprint);
}

/////////////////////////////////////////////////////////////////////////////
public mixed query(string element)
{
    mixed ret = 0;
    switch (element)
    {
        case "encumberance":
        {
            ret = member(itemData, "encumberance") ? itemData["encumberance"] :
                materialsObject()->getBlueprintModifier(this_object(), "default encumberance");
            break;
        }
        case "material":
        {
            ret = member(itemData, "material") ? itemData["material"] :
                materialsObject()->getBlueprintModifier(this_object(), "default material");
            break;
        }
        default:
        {
            ret = "item"::query(element);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkSetGuilds(mapping guilds)
{
    int ret = 0;
    
    if(!guilds || !mappingp(guilds) || (member(guilds, "prohibited") &&
       member(guilds, "allowed")) || (member(guilds, "prohibited") &&
       !pointerp(guilds["prohibited"])) || (member(guilds, "allowed") &&
       !pointerp(guilds["allowed"])))
    {
        raise_error("Equipment: The passed 'guilds' data is not properly "
            "constructed. It must contain only one of 'prohibited' or "
            "'allowed'.\n");
    }
    else
    {
        object guildDictionary = loadBlueprint(GuildsBlueprint);
        if(!guildDictionary || (member(guilds, "prohibited") &&
           !guildDictionary->isValidGuildSet(guilds["prohibited"])) ||
           (member(guilds, "allowed") &&
           !guildDictionary->isValidGuildSet(guilds["allowed"])))
        {
            raise_error("Equipment: The passed 'guilds' mapping contains "
                "an invalid guild.\n");
        }
        else
        {
            ret = 1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkSkills(mapping data)
{
    int ret = 0;
    object skills = loadBlueprint(SkillsBlueprint);
    if(data && mappingp(data) && skills && objectp(skills))
    {
        ret = 1;
        string *skillPrereqs = m_indices(data);
        foreach(string skill in skillPrereqs)
        {
            ret &&= skills->isValidSkill(skill);
        }
    }
    
    if(!ret)
    {
        raise_error(sprintf("Equipment: The 'skills' element must be"
            " a string as defined in the keys of the skills mapping in %s.\n",
            SkillsBlueprint));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkValidPrerequisites(mapping data)
{
    // These are optional prerequisites in addition to the more common
    // guild, skills, and owner prerequisites. I'm not entirely sure why
    // I broke those out of here, but I did. Deal with it.
    int ret = mappingp(data);
    
    if(member(data, "level"))
    {
        ret &&= intp(data["level"]);
    }
    if(member(data, "race"))
    {
        object races = loadBlueprint(RacesBlueprint);
        if(races)
        {
            ret &&= races->isValidRace(data["race"]);
        }
    }
    
    if(member(data, "research"))
    {
        ret &&= mappingp(data["research"]);
    }
    if(member(data, "quests"))
    {
        ret &&= mappingp(data["quests"]);
    }
    if(member(data, "skills") && mappingp(data["skills"]))
    {
        ret &&= checkSkills(data["skills"]);
    }
    if(member(data, "guilds") && mappingp(data["guilds"]))
    {
        ret &&= checkSetGuilds(data["guilds"]);
    }

    if(ret)
    {
        itemData["prerequisites"] = data + ([ ]);
    }
    else
    {
        raise_error("Equipment: The passed 'prerequisites' mapping is invalid.\n");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int levelPrerequisiteMet(mapping data, object user)
{
    int ret = 1;
    if(member(data, "level") && intp(data["level"]) &&
       function_exists("effectiveLevel", user))
    {
        ret &&= (user->effectiveLevel() >= data["level"]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int racePrerequisiteMet(mapping data, object user)
{
    int ret = 1;
    if(member(data, "race") && stringp(data["race"]) &&
       function_exists("Race", user))
    {
        ret &&= (user->Race() == data["race"]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int researchPrerequisiteMet(mapping data, object user)
{
    int ret = 1;
    if(member(data, "research") && mappingp(data["research"]))
    {
        string *research = m_indices(data["research"]);
        foreach(string researchItem : research)
        {
            if(researchItem && stringp(researchItem) &&
               function_exists("isResearched", user))
            {
                ret &&= user->isResearched(researchItem);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int questPrerequisiteMet(mapping data, object user)
{
    int ret = 1;
    if(member(data, "quests") && mappingp(data["quests"]))
    {
        string *quests = m_indices(data["quests"]);
        foreach(string quest : quests)
        {
            if(quest && stringp(quest) &&
               function_exists("questIsCompleted", user))
            {
                ret &&= user->questIsCompleted(quest);
            }
        }
    }
    return ret;
}   

/////////////////////////////////////////////////////////////////////////////
private nomask int guildPrerequisiteMet(mapping data, object user)
{
    int ret = 1;
    if(member(data, "guilds") && mappingp(data["guilds"]))
    {
        string failMessage = 
            "Your guild duties prevent you from using this item.";        
        if(member(data["guilds"], "message") && 
           stringp(data["guilds"]["message"]))
        {
            failMessage = data["guilds"]["message"];
        }
        notify_fail(sprintf("%s\n", failMessage));
    
        if(member(data["guilds"], "allowed") && 
           pointerp(data["guilds"]["allowed"]))
        {
            int canJoin = 0;
            foreach(string guild in data["guilds"]["allowed"])
            {
                canJoin ||= user->memberOfGuild(guild);
            }
            ret &&= canJoin;
        }
        else if(member(data["guilds"], "prohibited") && 
           pointerp(data["guilds"]["prohibited"]))
        {
            int canJoin = 0;
            foreach(string guild in data["guilds"]["prohibited"])
            {
                canJoin ||= !user->memberOfGuild(guild);
            }
            ret &&= canJoin;
        }
    }
    return ret;
}   

/////////////////////////////////////////////////////////////////////////////
private nomask int skillPrerequisiteMet(mapping data, object user)
{
    int ret = 1;
    if(member(data, "skills") && mappingp(data["skills"]))
    {
        string *skills = m_indices(data["skills"]);
        foreach(string skill : skills)
        {
            if(skill && stringp(skill) && intp(data["skills"][skill]) &&
               function_exists("getSkill", user))
            {
                ret &&= (user->getSkill(skill) >= data["skills"][skill]);
            }
        }
    }    
    return ret;
}   
       
/////////////////////////////////////////////////////////////////////////////
private nomask int prerequisitesMet(object user)
{
    int ret = 1;
    
    if(user && objectp(user) && member(itemData, "prerequisites") &&
       mappingp(itemData["prerequisites"]))
    {
        mapping data = itemData["prerequisites"];
        ret &&= levelPrerequisiteMet(data, user) &&
                racePrerequisiteMet(data, user) &&
                researchPrerequisiteMet(data, user) &&
                questPrerequisiteMet(data, user) &&
                guildPrerequisiteMet(data, user) &&
                skillPrerequisiteMet(data, user);  
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public varargs int set(string element, mixed data)
{
    int ret = 0;
    
    if(element && stringp(element))
    {
        if(member(prohibitedKeys, element) < 0)
        {
            switch(element)
            {
                case "equipment locations":
                {
                    if(data && intp(data))
                    {
                        itemData[element] = data;
                        ret = 1;                        
                    }
                    else
                    {
                        raise_error(sprintf("Equipment: The passed '%s' data "
                            "must be an integer.\n", element));
                    }
                    break;
                }
                case "equip message":
                case "unequip message":
                {
                    if(data && stringp(data))
                    {
                        itemData[element] = data;
                        ret = 1;                        
                    }
                    else
                    {
                        raise_error(sprintf("Equipment: The passed '%s' data "
                            "must be a string.\n", element));
                    }
                    break;                
                }
                case "equip method":
                case "unequip method":
                {
                    if(data && stringp(data) && 
                       function_exists(data, this_object()))
                    {
                        itemData[element] = data;
                        ret = 1;                        
                    }
                    else
                    {
                        raise_error(sprintf("Equipment: The passed '%s' %s "
                            "must be a function that exists in this item.\n", 
                            data, element));
                    }
                    break;                
                }
                case "cursed":
                {
                    if(data && mappingp(data) && member(data, "equip message") 
                       && member(data, "failed unequip message"))
                    {
                        itemData[element] = data + ([ ]);
                        ret = 1;                        
                    }
                    else
                    {
                        raise_error("Equipment: The cursed element must be a "
                            "mapping containing the 'equip message' and "
                            "'failed unequip message' keys.\n");
                    }
                    break;
                }
                case "prerequisites":
                {
                    ret = checkValidPrerequisites(data);
                    break;
                }
                case "blueprint":
                {
                    raise_error("Equipment: The blueprint can only be set from "
                        "a derived type.\n");
                            break;
                }
                default:
                {
                    ret = "item"::set(element, data);
                }
            }
        }
        else
        {
            raise_error(sprintf("Equipment: It is illegal to set the '%s' "
                "element for this type of object.\n", element));
        }
    }   

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canEquip(object user)
{
    int ret = prerequisitesMet(user);
    
    if(function_exists("spellAction", user) && user->spellAction())
    {
        ret = 0;
        notify_fail("You can't do actions that quickly.\n");
    }
    else if(user && function_exists("RealName", user) && query("owner"))
    {
        ret &&= query("owner") == user->RealName();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int equip(string item)
{
    int ret = 0;
    
    object env = environment(this_object());
    if(item && id(item) && env && function_exists("equip", env) &&
       !env->isEquipped(this_object()))
    {
        ret = env->equip(this_object());
        
        if(ret)
        {
            if(query("equip message"))
            {
                outputMessageFromTemplate(query("equip message"));
            }
            else
            {
                write("Ok.\n");

                if (env->has("materialAttributes"))
                {
                    say(sprintf("%s equips %s.\n", env->Name(), query("name")));
                }
            }
            if(query("equip method") && 
               function_exists(query("equip method"), this_object()))
            {
                call_other(this_object(), query("equip method"));
            }
            mapping curse = query("cursed");
            if(curse && mappingp(curse) && member(curse, "equip message"))
            {
                outputMessageFromTemplate(curse["equip message"]);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canUnequip()
{
    int ret = 0;

    mapping curse = query("cursed");
    object env = environment(this_object());
    
    if(curse && mappingp(curse) && 
       member(curse, "failed unequip message"))
    {
        notify_fail(curse["failed unequip message"]);
    }
    else if(env && function_exists("spellAction", env) && env->spellAction())
    {
        notify_fail("You can't do actions that quickly.\n");
    }
    else
    {
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public varargs int unequip(string item, int silently)
{
    int ret = 0;
    
    if(item && id(item))
    {
        object env = environment(this_object());
        if (mappingp(query("cursed")) && member(query("cursed"), "failed unequip message")
            && !silently)
        {
            outputMessageFromTemplate(query("cursed")["failed unequip message"]);
        }
        else if(env && function_exists("isEquipped", env) && 
           env->isEquipped(this_object()))
        {
            ret = env->unequip(this_object(), silently);
            
            if(ret)
            {
                if(!silently)
                {
                    if(query("unequip message"))
                    {
                        outputMessageFromTemplate(query("unequip message"));
                    }
                    else
                    {
                        write("Ok.\n");
                        if (env->has("materialAttributes"))
                        {
                            say(sprintf("%s unequips %s.\n", env->Name(),
                                query("name")));
                        }
                    }
                }
                if(query("unequip method") && 
                   function_exists(query("unequip method"), this_object()))
                {
                    call_other(this_object(), query("unequip method"));
                }
            }
        }
        else
        {
            notify_fail(
                sprintf("You do not currently have a '%s' equipped.\n", item));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public varargs int drop(int silently)
{
    int ret = !canUnequip();
    
    object env = environment(this_object());
    if(env && function_exists("isEquipped", env) && 
       env->isEquipped(this_object()) && environment(env))
    {
        ret = !unequip(query("name"), silently);

        if(!ret)
        {
            move_object(this_object(), environment(env));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    add_action("equip", "equip");
    add_action("unequip", "unequip");
    item::init();
}

