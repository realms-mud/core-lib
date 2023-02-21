//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";

private nosave string AttacksBlueprint = "/lib/dictionaries/attacksDictionary.c";
private nosave string BonusesBlueprint = "/lib/dictionaries/bonusesDictionary.c";
protected nosave string MaterialsBlueprint = "/lib/dictionaries/materialsDictionary.c";
protected nosave object MessageParser = load_object("/lib/core/messageParser.c");
private nosave object MaterialsObject = getDictionary("materials");

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
//  "identified":      // True if the item has been identified
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
private string *prohibitedKeys = ({ "armor class", "defense class",
    "weapon class", "hit method", "armor type", "weapon type", "offhand",
    "equip message", "equip method", "equipment locations", "prerequisites",
    "unequip message", "unequip method", "cursed" });

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{

}

/////////////////////////////////////////////////////////////////////////////
public void create()
{
    Setup();
}

/////////////////////////////////////////////////////////////////////////////
protected nomask object materialsObject()
{
    return MaterialsObject;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int isValidBonus(string bonus, int amount)
{
    int ret = 0;
    object bonusesDictionary = getDictionary("bonuses");
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
private nomask mapping addServiceEnchantments(mapping enchantments, string service)
{
    mapping ret = enchantments ? enchantments + ([]) : ([]);
    object user = environment();

    if (user && function_exists(sprintf("%sEnchantments", service), user))
    {
        mapping itemEnchantments = call_direct(user,
            sprintf("%sEnchantments", service));

        string *keys = m_indices(itemEnchantments);
        if (sizeof(keys))
        {
            foreach(string key in keys)
            {
                if (!member(ret, key))
                {
                    ret[key] = itemEnchantments[key];
                }
                else
                {
                    ret[key] += itemEnchantments[key];
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getModifierEnchantments(mapping enchantments)
{
    mapping ret = enchantments ? enchantments + ([]) : ([]);
    object user = environment();
    if (user)
    {
        object *modifiers = user->registeredInventoryObjects();
        if (sizeof(modifiers))
        {
            foreach(object modifier in modifiers)
            {
                string *bonuses = modifier->query("bonuses");
                if (sizeof(bonuses))
                {
                    bonuses = filter(bonuses,
                        (: !sizeof(regexp(({ $1 }) , "crafting")) &&
                            sizeof(regexp(({ $1 }), 
                                "bonus [^ ]+ enchantment$")) :));
                    if (sizeof(bonuses))
                    {
                        foreach(string bonus in bonuses)
                        {
                            string enchantment = regreplace(bonus,
                                "bonus ([^ ]+) enchantment$", "\\1");
                            if (!member(ret, enchantment))
                            {
                                ret[enchantment] = modifier->query(bonus);
                            }
                            else
                            {
                                ret[enchantment] += modifier->query(bonus);
                            }
                        }
                    }
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public mixed query(string element)
{
    mixed ret = 0;
    
    if(element && stringp(element))
    {
        switch (element)
        {
            case "long":
            {
                ret = member(itemData, "long") ? itemData["long"] :
                    materialsObject()->getBlueprintDetails(
                        this_object(), "default description") || query("short");
                break;
            }
            case "description":
            {
                ret = member(itemData, "description") ? itemData["description"] :
                    materialsObject()->getBlueprintDetails(this_object(), 
                        "default description") || query("short");
                break;
            }
            case "primary component":
            {
                ret = member(itemData, "primary component") ? 
                    itemData["primary component"] :
                    materialsObject()->getBlueprintDetails(this_object(), 
                        "primary component");
                break;
            }
            case "value":
            {
                ret = member(itemData, "value") ? itemData["value"] :
                    materialsObject()->getDefaultValue(this_object());

                if (ret < 0)
                {
                    ret = 0;
                }

                if (member(itemData, "crafting value multiplier"))
                {
                    int increase = itemData["crafting value multiplier"];
                    ret = to_int(((100.0 + increase) / 100.0) * ret);
                }
                break;
            }
            case "charged":
            {
                if (member(itemData, "charges") && itemData["charges"])
                {
                    ret = 1;
                }
                break;
            }
            case "crafting type":
            {
                ret = member(itemData, "crafting type") ? itemData["crafting type"] :
                    materialsObject()->getBlueprintDetails(
                        this_object(), "subtype");

               if (!getDictionary("crafting")->isValidType(ret))
                {
                    ret = materialsObject()->getBlueprintDetails(
                        this_object(), "skill to use");
                }
                
                break;
            }
            case "crafting guilds":
            {
                object guilds = getDictionary("guilds");
                if (guilds)
                {
                    ret = guilds->guildsInClass("crafting");
                }
                break;
            }
            case "short":
            {
                ret = itemData["short"] ? itemData["short"] : query("name");
                break;
            }
            case "bonuses":
            {
                ret = filter(m_indices(itemData),
                    (: return sizeof(regexp(({ $1 }), "bonus")) > 0; :));
                break;
            }
            case "enchantments":
            {
                ret = addServiceEnchantments(
                    addServiceEnchantments(
                        getModifierEnchantments(itemData["enchantments"]), 
                        "research"), "traits");
               
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
            case "low light description":
            {
                ret = member(itemData, "low light description") ?
                    itemData["low light description"] :
                    "An item whose details cannot be seen in the low light";
                break;
            }
            case "dim light description":
            {
                ret = member(itemData, "dim light description") ?
                    itemData["dim light description"] : 
                    "An item unidentifiable in the low light";
                break;
            }
            case "some light description":
            {
                ret = member(itemData, "some light description") ?
                    itemData["some light description"] : query("type");
                break;
            }
            default:
            {
                if(member(itemData, element) && itemData[element])
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
        object damageType = getDictionary("attacks");
        if(damageType)
        {
            foreach(string dmgType in m_indices(data))
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
    object materials = getDictionary("materials");
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

                    if (ret && member(itemData, "crafting enchantment power"))
                    {
                        int enhanceBy = itemData["crafting enchantment power"];

                        string *enchantments = m_indices(data);
                        foreach(string enchantment in enchantments)
                        {
                            data[enchantment] += enhanceBy;
                        }
                    }

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
        object owner = environment();
        if (objectp(owner) && owner->isRealizationOfLiving())
        {
            owner->updateInventoryCache(this_object(), element);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int unset(string element)
{
    int ret = 0;
    if (member(itemData, element))
    {
        ret = 1;
        m_delete(itemData, element);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
static nomask string parseTemplate(string template)
{
    string message = template;
    if(message && MessageParser && objectp(MessageParser))
    {
        message = MessageParser->parseEfunCall(message);

        object owner = environment(this_object());    
        if(owner && objectp(owner))
        {
            int isSecondPerson = 1;
            message = MessageParser->parseTargetInfo(message, "User", owner,
                isSecondPerson);
            message = MessageParser->parseVerbs(message, isSecondPerson);
            message = MessageParser->capitalizeSentences(message);
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
    if (MessageParser && objectp(MessageParser))
    {
        string message = MessageParser->parseEfunCall(template);

        object owner = environment(this_object());
        if (owner && objectp(owner) && function_exists("isEquipped", owner) &&
            environment(owner))
        {
            string parsedMessage;
            object *characters = filter(all_inventory(environment(owner)),
                (: $1->isRealizationOfLiving() :));

            foreach(object person in characters)
            {
                if (person && objectp(person))
                {
                    if (person == owner)
                    {
                        parsedMessage = MessageParser->parseVerbs(message, 1);
                        parsedMessage = 
                            MessageParser->parseTargetInfo(parsedMessage, "User",
                            owner, 1);
                    }
                    else
                    {
                        parsedMessage = MessageParser->parseVerbs(message, 0);
                        parsedMessage = 
                            MessageParser->parseTargetInfo(parsedMessage, "User",
                            owner, 0);
                    }
                    tell_object(person, 
                        MessageParser->capitalizeSentences(parsedMessage));
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public varargs string short(int useLight)
{
    if (!query("short"))
    {
        raise_error("Item: No short description was set.\n");
    }

    string shortTemplate = (query("light") || useLight) ? query("short") : "";
    if (shortTemplate == "")
    {
        switch (isIlluminated())
        {
            case 1..2:
            {
                shortTemplate = "The silhouette of an item, but it is too "
                    "dark to identify it";
                break;
            }
            case 3..4:
            {
                shortTemplate = query("low light description");
                break;
            }
            case 5..6:
            {
                shortTemplate = query("dim light description");
                break;
            }
            case 7..8:
            {
                shortTemplate = query("some light description");
                break;
            }
            case 9..1000:
            {
                shortTemplate = query("short");
                break;
            }
            default:
            {
                shortTemplate = "";
                break;
            }
        }
    }

    if (shortTemplate && (shortTemplate != ""))
    {
        shortTemplate = parseTemplate(shortTemplate);
    }
    return shortTemplate;
}

/////////////////////////////////////////////////////////////////////////////
protected string itemStatistics(int doNotApplyUserStatistics)
{
    string ret = "";
    object itemTypes = MaterialsObject;
    if (MaterialsObject && objectp(MaterialsObject))
    {
        ret = MaterialsObject->getEquipmentStatistics(this_object(),
            (doNotApplyUserStatistics ? 0 : this_player()));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string describeCraftingMaterials()
{
    string ret = "";

    object itemTypes = getDictionary("crafting");
    if (itemTypes && objectp(itemTypes))
    {
        ret = itemTypes->getEquipmentMaterials(this_object());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public varargs string long(int doNotApplyUserStatistics)
{    
    string description = "";
    if (query("long") && (query("long") != ""))
    {
        object itemTypes = getDictionary("crafting");
        if (itemTypes && objectp(itemTypes))
        {
            description += itemTypes->addMaterialsToDescription(this_object());
        }
        else
        {
            description += query("long");
        }
    }
    else
    {
        description += query("short");
    }

    if (query("identified") && query("additional long"))
    {
        description += sprintf(" %s", query("additional long"));
    }

    string materials = describeCraftingMaterials();
    if (materials != "")
    {
        description += " " + materials;
    }
    description = format(description, 78);

    string statistics = itemStatistics(doNotApplyUserStatistics);
    if(statistics != "")
    {
        description += statistics;
    }

    description += "\n";

    return description;
}

/////////////////////////////////////////////////////////////////////////////
public int id(string item)
{
    string *aliases = ({ query("name"), lower_case(query("name")), query("short"),
        lower_case(query("short")) });
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
