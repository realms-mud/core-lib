//*****************************************************************************
// Class: item
// File Name: item.c
//
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
// Description: This class defines exactly what items that can be carried are
//              and as such, must be inherited by all carryable items. 
//
//*****************************************************************************
virtual inherit "/lib/core/thing.c";

private nosave string AttacksBlueprint = "/lib/dictionaries/attacksDictionary.c";
private nosave string MaterialsBlueprint = "/lib/dictionaries/materialsDictionary.c";
private nosave string MessageParser = "/lib/core/messageParser.c";
private nosave string BonusesBlueprint = "/lib/dictionaries/bonusesDictionary.c";

protected mapping itemData = ([ 
//  "aliases": ({ }),  // string array of alternate names for item
//  "bonus <thing>":   // attribute/hp/etc bonuses while equipped. Examples:
//  "bonus hit points": 20     // give 20 extra hit points while equipped
//  "bonus heal hit points": 3 // heal extra 3 hp per heart_beat heal interval
//  "bonus heal hit points rate": 2 // decrease heal (hp) interval by 2 seconds
//  "bonus strength": 2        // add 2 to the equipper's strength stat
//  "bonus long sword": 4      // add 4 to the longsword skill of the equipper
//  "bonus armor class": 2     // add 2 the the equipper's armor class  
//  "charges":         // number of charges the item has
//  "craftsmanship":   // The skill of the craftsman who created the item
//  "skill penalty":   // The base skill penalty for the item
//  "destruct method": // function existing in item that is called on destruct
//  "enchantments": ([ // adds damage of <key> type to attacks by user
//      "fire": 20     // an example that adds 20 fire damage while equipped
//  ]),                // see attacks.c for details
//  "identified":
//  "info":            // Special item information used by identify skill
//  "light": 1,        // the piece of equipment is a light source
//  "long":            // Item's long description - applied via parseDescription
//  "additional long": // Additional description displayed after identified
//  "user description":// Description displayed when looking at item's user
//  "material":        // Material the item is made out of - see materials.c
//  "name":            // The name of the item
//  "no steal":        // flag set to true if the item cannot be stolen
//  "no sell":         // flag set to true if the item cannot be sold
//  "owner":           // The name of the item's owner
//  "read message unidentified":// The message returned when the item is "read"
//  "read message identified":  // either while identified or unidentified
//  "register event handler":   // Set to true if this has events that must be
//                              // (un)registered when (un)equipped. Must create
//                              // an instance with the desired event handler
//  "resistances": ([  // adds protection from damage of <key> type
//      "fire": 10
//  ]),
//  "short":           // short description
//  "value":           // Value / base buy cost of the item
//  "weight":          // weight of the item - separate from encumberance
]);

/////////////////////////////////////////////////////////////////////////////
protected nomask object loadBlueprint(string blueprint)
{
    object ret = 0;
    if(blueprint && stringp(blueprint) && (file_size(blueprint) > 0))
    {
        ret = load_object(blueprint);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string *prohibitedKeys = ({ "armor class", "defense class",
    "weapon class", "hit method", "armor type", "weapon type", "offhand",
    "equip message", "equip method", "equipment locations", "prerequisites",
    "unequip message", "unequip method", "cursed" });

/////////////////////////////////////////////////////////////////////////////
protected nomask int isValidBonus(string bonus, int amount)
{
    int ret = 0;
    object bonusesDictionary = loadBlueprint(BonusesBlueprint);
    if(bonus && stringp(bonus) && amount && intp(amount) && bonusesDictionary)
    {
        ret = bonusesDictionary->isValidBonusModifier(bonus, amount);
    }
    
    if(!ret)
    {
        raise_error(sprintf("Item: The 'bonus <thing>' element must be"
            " a string as defined in the keys of the bonusList mapping in %s "
            "and it must be set to an appropriate value.\n",
            BonusesBlueprint));
    }    
    return ret;
}
    
/////////////////////////////////////////////////////////////////////////////
public mixed query(string element)
{
    mixed ret = 0;
    
    if(element && stringp(element))
    {
        if (element == "long")
        {
            ret = member(itemData, "long") ? itemData["long"] :
                loadBlueprint(MaterialsBlueprint)->getBlueprintModifier(
                    this_object(), "default description");
        }
        else if(member(itemData, element) && itemData[element])
        {
            if(pointerp(itemData[element]))
            {
                ret = itemData[element] + ({ });
            }
            else if(mappingp(itemData[element]))
            {
                ret = itemData[element] + ([ ]);
            }
            else
            {
                ret = itemData[element];
            }
        }
        else if(member(itemData, element))
        {
            // handles boolean 'existence' data
            ret = 1;
        }
        else
        {
            switch(element)
            {
                case "charged":
                {
                    if(member(itemData, "charges") && itemData["charges"])
                    {
                        ret = 1;
                    }
                    break;
                }
                case "short":
                {
                    // This is only happens if short is not set
                    ret = query("name");
                    break;
                }
                case "bonuses":
                {
                    ret = filter(m_indices(itemData),
                        (: return sizeof(regexp(({ $1 }), "bonus")) > 0; :));
                    break;
                }
                case "all":
                {
                    ret = save_value(itemData);
                    break;
                }
                case "type":
                {
                    ret = "item";
                    break;
                }
            }
        }
    }
                    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkDamageType(string element, mapping data)
{
    int ret = 0;

    if(data && mappingp(data))
    {
        ret = 1;
        object damageType = loadBlueprint(AttacksBlueprint);
        if(damageType)
        {
            foreach(string dmgType : m_indices(data))
            {
                if(!damageType->isValidDamageType(dmgType) ||
                    damageType->isOutOfRange(dmgType, 
                    data[dmgType]))
                {
                    ret = 0;
                }
            }
        }
        else
        {
            ret = 0;
        }
        if(!ret)
        {
            raise_error(sprintf("Item: The %s element must be"
                " a mapping containing a valid damage type with a "
                "valid range as defined in %s", element,
                AttacksBlueprint));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkMaterial(string data)
{
    int ret = 0;
    object materials = loadBlueprint(MaterialsBlueprint);
    if(data && stringp(data) && materials && objectp(materials))
    {
        ret = materials->isValidMaterial(data);
    }
    
    if(!ret)
    {
        raise_error(sprintf("Item: The 'material' element must be"
            " a string as defined in the keys of the materials mapping in %s.\n",
            MaterialsBlueprint));
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
            ret = 1;
            
            switch(element)
            {
                case "type":
                {
                    raise_error("Item: You cannot modify the item's 'type'.\n");
                    break;
                }
                case "aliases":
                {
                    if(!data || !pointerp(data) || !sizeof(data) || 
                       !stringp(data[0]))
                    {
                        ret = 0;
                        raise_error("Item: The passed 'aliases' data "
                            "must be an array of strings.\n");
                    }
                    break;
                }
                case "charges":
                case "craftsmanship":
                case "skill penalty":
                {
                    if(!data || !intp(data) || (data < 1))
                    {
                        ret = 0;
                        raise_error(sprintf("Item: The passed '%s' data "
                            "must be an integer greater than 0.\n", element));
                    }
                    break;
                }
                case "value":
                case "weight":
                case "enchanted":
                case "encumberance":
                case "no steal":
                case "no sell":
                case "register event handler":
                {
                    if(!data || !intp(data))
                    {
                        ret = 0;
                        raise_error(sprintf("Item: The passed '%s' data "
                            "must be an integer.\n", element));
                    }
                    break;
                }
                case "info":
                case "long":
                case "additional long":
                case "user description":
                case "name":
                case "owner":
                case "read message unidentified":
                case "read message identified":            
                case "short":
                case "all":
                {
                    if(!data || !stringp(data))
                    {
                        ret = 0;
                        raise_error(sprintf("Item: The passed '%s' data "
                            "must be a string.\n", element));
                    }
                    break;                
                }
                case "light":
                {
                    if(!data || !intp(data))
                    {
                        ret = 0;
                        raise_error(sprintf("Item: The passed '%s' data "
                            "must be an integer.\n", element));
                    }
                    break;                
                }
                case "destruct method":
                {
                     if(!data || !stringp(data) || 
                        !function_exists(data, this_object()))
                    {
                        ret = 0;
                        raise_error(sprintf("Item: The passed '%s' %s "
                            "must be a function that exists in this item.\n", 
                            data, element));
                    }
                    break;                
                }
                case "enchantments":
                case "resistances":
                {
                    ret = checkDamageType(element, data);

                    if(ret)
                    {
                        set("enchanted", query("enchanted") + 1);
                    }
                    break;
                }
                case "material":
                {
                    ret = checkMaterial(data);
                    break;
                }
                default:
                {
                    string bonusToCheck = 0;
                    if(sscanf(element, "bonus %s", bonusToCheck))
                    {
                        ret = isValidBonus(bonusToCheck, data);
                        if (ret)
                        {
                            set("enchanted", query("enchanted") + 1 + (data / 2));
                        }
                    }
                    break;
                }
            }
        }
        else
        {
            raise_error(sprintf("Item: It is illegal to set the '%s' "
                "element for this type of object.\n", element));
        }
    }   

    if(ret)
    {
        if (element == "all")
        {
            itemData = restore_value(data);
        }
        else if(mappingp(data))
        {
            itemData[element] = data + ([ ]);
        }
        else if(pointerp(data))
        {
            itemData[element] = data + ({ });
        }
        else
        {
            itemData[element] = data;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
static nomask string parseTemplate(string template)
{
    string message = template;
    object parser = loadBlueprint(MessageParser);
    if(parser && objectp(parser))
    {
        message = parser->parseEfunCall(message);

        object owner = environment(this_object());    
        if(owner && objectp(owner))// && function_exists("isEquipped", owner))
        {
            int isSecondPerson = 1;
            message = parser->parseTargetInfo(message, "User", owner, 
                isSecondPerson);
            message = parser->parseVerbs(message, isSecondPerson);
            message = parser->capitalizeSentences(message);
        }
    }
    return message;
}

/////////////////////////////////////////////////////////////////////////////
static nomask void outputMessageFromTemplate(string template)
{
    // Messages have several key elements that can be replaced:
    // ##AttackerName## - Attacker's name
    // ##AttackerWeapon## - type of attacker's weapon (longsword, short sword,
    //   claymore...)
    // ##AttackerPossessive## - Attacker possessive / your
    // ##AttackerObjective## - Attacker's objective / you
    // ##AttackerSubjective## - Attacker's subjective/pronoun / you
    // ##Target[NWPOS]## - Target's (one of above 5)
    // ##HitDictionary## - random word from the hit dictionary (slash/slashes,
    //   chop/chops)
    // ##SimileDictionary## - random word from the simile dictionary
    // There's another special case for possessive:
    // ##[AT]P[::N]## - ##AP::N## -> "Bob's" or "your" for attacker named Bob
    //                  ##TP::N## -> "Bob's" or "your" for target named Bob
    // ##efun::key|file|target|this::object|filename|this::function##

    // Replace method calls
    object parser = loadBlueprint(MessageParser);
    if (parser && objectp(parser))
    {
        string message = parser->parseEfunCall(template);

        object owner = environment(this_object());
        if (owner && objectp(owner) && function_exists("isEquipped", owner) &&
            environment(owner))
        {
            string parsedMessage;
            foreach(object person in all_inventory(environment(owner)))
            {
                if (person && objectp(person))
                {
                    if (person == owner)
                    {
                        parsedMessage = parser->parseVerbs(message, 1);
                        parsedMessage = parser->parseTargetInfo(parsedMessage, "User",
                            owner, 1);
                    }
                    else
                    {
                        parsedMessage = parser->parseVerbs(message, 0);
                        parsedMessage = parser->parseTargetInfo(parsedMessage, "User",
                            owner, 0);
                    }
                    tell_object(person, parser->capitalizeSentences(parsedMessage));
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public string short()
{
    if (!query("short"))
    {
        raise_error("Item: No short description was set.\n");
    }
    return parseTemplate(query("short"));
}

/////////////////////////////////////////////////////////////////////////////
protected string itemStatistics()
{
    string ret = "";
    object itemTypes = load_object(MaterialsBlueprint);
    if (itemTypes && objectp(itemTypes))
    {
        ret = itemTypes->getEquipmentStatistics(this_object(), this_player());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public string long()
{    
    string description = "";
    if (query("long") && (query("long") != ""))
    {
        description += query("long");
    }
    else
    {
        description += query("short");
    }

    if (query("identified") && query("additional long"))
    {
        description += sprintf(" %s", query("additional long"));
    }

    string statistics = itemStatistics();
    if(statistics != "")
    {
        description += "\n" + statistics;
    }

    description += "\n";

    return description;
}

/////////////////////////////////////////////////////////////////////////////
public int id(string item)
{
    string *aliases = ({ query("name") });
    if (pointerp(query("aliases")))
    {
        aliases += query("aliases");
    }
    return (item && stringp(item) && aliases && (member(aliases, item) > -1));
}

/////////////////////////////////////////////////////////////////////////////
public string readMessage(string item)
{
    string msg = 0;
    if(id(item))
    {
        if(member(itemData, "identified") && 
            member(itemData, "read message identified"))
        {
            msg = itemData["read message identified"];
        }
        else if(member(itemData, "read message unidentified"))
        {
            msg = itemData["read message unidentified"];
        }
    }
    return msg;
}

/////////////////////////////////////////////////////////////////////////////
public int read(string item)
{
    int ret = 0;
    notify_fail("Read what?\n");
    
    string message = readMessage(item);
    if(message)
    {
        ret = 1;
        printf("%s\n", message);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public varargs int drop(int silently)
{
    int ret = 1;
    if (!query("undroppable"))
    {
        object env = environment(this_object());
        if (env && environment(env))
        {
            ret = 0;
            move_object(this_object(), environment(env));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int identify()
{
    int ret = 0;
    if(!query("identified"))
    {
        ret = set("identified",1);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    add_action("read", "read");
}

/////////////////////////////////////////////////////////////////////////////
public int get()
{ 
    return !query("ungettable");
}

/////////////////////////////////////////////////////////////////////////////
public int isContainer()
{
    return 0;
}
