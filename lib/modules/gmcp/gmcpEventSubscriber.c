//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/include/inventory.h"

private nosave object player = 0;

/////////////////////////////////////////////////////////////////////////////
public void create()
{
}

/////////////////////////////////////////////////////////////////////////////
public void setPlayer(object who)
{
    player = who;
}

/////////////////////////////////////////////////////////////////////////////
public object getPlayer()
{
    return player;
}

/////////////////////////////////////////////////////////////////////////////
private mapping vitalsSnapshot(object player)
{
    return ([
        "hitPoints": ([
            "current": player->hitPoints(),
            "max": player->maxHitPoints()
        ]),
        "spellPoints": ([
            "current": player->spellPoints(),
            "max": player->maxSpellPoints()
        ]),
        "staminaPoints": ([
            "current": player->staminaPoints(),
            "max": player->maxStaminaPoints()
        ])
    ]);
}

/////////////////////////////////////////////////////////////////////////////
private mapping attributesSnapshot(object player)
{
    mapping ret = ([]);

    object attributeService = getService("attribute");
    if (objectp(attributeService))
    {
        foreach (string attribute in attributeService->attributes())
        {
            int effective = player->attributeValue(attribute);
            int base = player->attributeValue(attribute, 1);

            ret[attribute] = ([
                "value": effective,
                "base": base,
                "bonus": effective - base
            ]);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private mixed guildsSnapshot(object player)
{
    mixed ret = ({});

    string *guilds = player->memberOfGuilds();
    string primary = player->primaryGuild();

    if (sizeof(guilds))
    {
        foreach (string guild in guilds)
        {
            ret += ({ ([
                "name": guild,
                "level": player->guildLevel(guild),
                "experience": player->guildExperience(guild),
                "experienceToNextLevel": player->experienceToNextLevel(guild),
                "rank": player->guildRank(guild) || "",
                "primary": (guild == primary) ? 1 : 0
            ]) });
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private mapping weaponCombatSnapshot(object player, object weapon, string slot)
{
    mapping ret = 0;

    if (objectp(weapon))
    {
        int attack = player->calculateAttack(0, weapon, 1);
        int damage = player->calculateDamage(weapon, "physical", 1);
        if (!damage)
        {
            damage = 1;
        }

        ret = ([
            "slot": slot,
            "name": weapon->query("short"),
            "attackLow": attack - 25,
            "attackHigh": attack + 75,
            "damageLow": to_int(damage * 7.0 / 8.0),
            "damageHigh": to_int(damage * 9.0 / 8.0)
        ]);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private mapping combatSnapshot(object player)
{
    mixed weapons = ({});

    object primary = player->equipmentInSlot("wielded primary");
    if (objectp(primary))
    {
        weapons += ({ weaponCombatSnapshot(player, primary, "wielded primary") });
    }

    object offhand = player->equipmentInSlot("wielded offhand");
    if (objectp(offhand))
    {
        weapons += ({ weaponCombatSnapshot(player, offhand, "wielded offhand") });
    }

    int defend = player->calculateDefendAttack();
    int soak = player->calculateSoakDamage("physical");

    return ([
        "weapons": weapons,
        "defendAttackLow": defend - abs(defend / 2),
        "defendAttackHigh": defend,
        "soakLow": soak - abs(soak / 2),
        "soakHigh": soak,
        "encumberance": player->inventoryGetEncumberance()
    ]);
}

/////////////////////////////////////////////////////////////////////////////
private string *equipSlotsForItem(object item)
{
    string *ret = ({});
    int locations = item->query("equipment locations");

    if (!intp(locations) || !locations)
    {
        return ret;
    }

    if ((locations & TwohandedWeapon) == TwohandedWeapon)
    {
        ret += ({ "wielded primary", "wielded offhand" });
    }
    else
    {
        if (locations & PrimaryWeapon)
        {
            ret += ({ "wielded primary" });
        }
        if (locations & OffhandWeapon)
        {
            ret += ({ "wielded offhand" });
        }
    }

    if (locations & Cloak)      { ret += ({ "cloak" }); }
    if (locations & Helmet)     { ret += ({ "helmet" }); }
    if (locations & Amulet)     { ret += ({ "amulet" }); }
    if (locations & Belt)       { ret += ({ "belt" }); }
    if (locations & ArmGreaves) { ret += ({ "arm greaves" }); }
    if (locations & LegGreaves) { ret += ({ "leg greaves" }); }
    if (locations & Gloves)     { ret += ({ "gloves" }); }
    if (locations & Bracers)    { ret += ({ "bracers" }); }
    if (locations & Boots)      { ret += ({ "boots" }); }
    if (locations & Armor)      { ret += ({ "armor" }); }
    if (locations & Ring1)      { ret += ({ "ring 1" }); }
    if (locations & Ring2)      { ret += ({ "ring 2" }); }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
// Authoritative item category for the client's inventory tab filtering.
// Derived from the server-side inheritance hierarchy (not from free-text
// name/type heuristics), so it always agrees with what the item actually is.
/////////////////////////////////////////////////////////////////////////////
private string categoryForItem(object item)
{
    string *inherits = inherit_list(item);

    if (member(inherits, "/lib/items/weapon.c") > -1)
    {
        return "weapon";
    }
    if (member(inherits, "/lib/items/armor.c") > -1)
    {
        return "armor";
    }
    if (member(inherits, "/lib/items/potion.c") > -1)
    {
        return "potion";
    }
    if (member(inherits, "/lib/items/material.c") > -1)
    {
        return "material";
    }
    if (member(inherits, "/lib/items/ingredient.c") > -1)
    {
        return "material";
    }
    if (member(inherits, "/lib/items/instrument.c") > -1)
    {
        return "weapon";
    }
    if (member(inherits, "/lib/items/food.c") > -1)
    {
        return "food";
    }
    if (member(inherits, "/lib/items/scroll.c") > -1)
    {
        return "scroll";
    }
    if (member(inherits, "/lib/items/rune.c") > -1)
    {
        return "rune";
    }
    if (member(inherits, "/lib/items/key.c") > -1)
    {
        return "key";
    }
    if (member(inherits, "/lib/items/book.c") > -1)
    {
        return "book";
    }
    if (member(inherits, "/lib/items/container.c") > -1)
    {
        return "container";
    }

    return "other";
}

/////////////////////////////////////////////////////////////////////////////
private mapping summarizeInventoryItem(object item, string slot)
{
    mapping ret = 0;

    if (objectp(item))
    {
        string type = item->query("weapon type") ||
            item->query("armor type") ||
            item->query("instrument type") || "";
        object materialsService = getService("materials");
        mapping details = materialsService ?
            materialsService->getItemDetails(item) : ([]);

        ret = ([
            "name": item->query("name"),
            "short": item->query("short"),
            "type": type,
            "category": categoryForItem(item),
            "details": details
        ]);

        if (stringp(slot))
        {
            ret["slot"] = slot;
        }
        else
        {
            string *equipSlots = equipSlotsForItem(item);
            if (sizeof(equipSlots))
            {
                ret["equipSlots"] = equipSlots;
            }
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private mapping skillsSnapshot(object player)
{
    mapping ret = ([]);
    object skillsService = getService("skills");

    if (!objectp(skillsService))
    {
        return ret;
    }

    string *types = ({ "combat", "crafting", "erudite", "subterfuge",
        "general", "magic", "language" });

    foreach (string type in types)
    {
        string *skillList = skillsService->validSkillsOfType(type);
        foreach (string skill in skillList)
        {
            int base = player->getSkill(skill, 1);
            int effective = player->getSkill(skill);
            if (base > 0 || effective > 0)
            {
                ret[skill] = ([
                    "value": effective,
                    "base": base,
                    "bonus": effective - base,
                    "type": type
                ]);
            }
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private mixed traitsSnapshot(object player)
{
    mixed ret = ({});
    object traitService = getService("traits");

    if (!objectp(traitService))
    {
        return ret;
    }

    string *traitList = player->Traits();
    foreach (string trait in traitList)
    {
        object traitObj = traitService->traitObject(trait);
        if (objectp(traitObj))
        {
            ret += ({ ([
                "name": (traitObj->query("name") || ""),
                "type": (traitObj->query("type") || ""),
                "root": (traitObj->query("root") || ""),
                "description": (traitObj->query("description") || "")
            ]) });
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private mapping researchSnapshot(object player)
{
    object researchService = getService("research");
    mixed trees = ({});

    string *availableTrees = player->availableResearchTrees();
    if (!pointerp(availableTrees))
    {
        availableTrees = ({});
    }

    foreach (string treePath in availableTrees)
    {
        object treeObj = researchService->researchTree(treePath);
        if (!objectp(treeObj))
        {
            continue;
        }

        mapping flatTree = treeObj->getFlattenedResearchTree(player);
        if (!mappingp(flatTree))
        {
            continue;
        }

        mixed nodes = ({});
        object *nodeObjects = m_indices(flatTree);

        foreach (object researchObj in nodeObjects)
        {
            string nodePath;
            mapping statusData;
            string nodeStatus;
            string *parents;

            if (!objectp(researchObj))
            {
                continue;
            }

            nodePath = program_name(researchObj);
            statusData = flatTree[researchObj];

            nodeStatus = "locked";
            if (mappingp(statusData))
            {
                if (member(statusData, "researched") != -1)
                {
                    nodeStatus = "known";
                }
                else if (member(statusData, "researching") != -1)
                {
                    nodeStatus = "in_progress";
                }
                else if (member(statusData, "can research") != -1)
                {
                    nodeStatus = "available";
                }
            }

            parents = treeObj->getParents(nodePath);
            if (!pointerp(parents))
            {
                parents = ({});
            }

            mixed prereqs = ({});
            mapping prereqMap = researchObj->getPrerequisites();
            if (mappingp(prereqMap))
            {
                string *prereqKeys = m_indices(prereqMap);
                foreach (string prereqKey in prereqKeys)
                {
                    mapping pd = prereqMap[prereqKey];
                    if (mappingp(pd))
                    {
                        string prereqType = (pd["type"] || "");
                        string displayKey = prereqKey;
                        if (prereqType == "research")
                        {
                            object rObj = getService("research")->researchObject(prereqKey);
                            if (objectp(rObj))
                            {
                                displayKey = (rObj->query("name") || prereqKey);
                            }
                        }
                        prereqs += ({ ([
                            "key": displayKey,
                            "type": prereqType,
                            "value": (pd["value"] || 0),
                            "guild": (pd["guild"] || "")
                        ]) });
                    }
                }
            }

            // modifiers (damage/effect scaling formulas)
            mixed *modifierData = researchObj->query("modifiers");
            mixed modifiers = ({});
            if (pointerp(modifierData))
            {
                foreach (mapping mod in modifierData)
                {
                    if (mappingp(mod))
                    {
                        modifiers += ({ ([
                            "type": (mod["type"] || ""),
                            "name": (mod["name"] || ""),
                            "formula": (mod["formula"] || ""),
                            "rate": (mod["rate"] || 0)
                        ]) });
                    }
                }
            }

            // damage/healing effect formulas
            string *effectTypes = ({
                "damage hit points", "damage spell points",
                "damage stamina points", "increase hit points",
                "increase spell points", "increase stamina points",
                "siphon hit points", "siphon spell points",
                "siphon stamina points"
            });
            mapping damageEffects = ([]);
            foreach (string effectType in effectTypes)
            {
                mixed *effectData = researchObj->query(effectType);
                if (pointerp(effectData) && sizeof(effectData))
                {
                    mixed *entries = ({});
                    foreach (mapping entry in effectData)
                    {
                        if (mappingp(entry))
                        {
                            entries += ({ ([
                                "probability": (entry["probability"] || 0),
                                "baseDamage": (entry["base damage"] || 0),
                                "range": (entry["range"] || 0)
                            ]) });
                        }
                    }
                    if (sizeof(entries))
                    {
                        damageEffects[effectType] = entries;
                    }
                }
            }

            // damage type
            string damageType = (researchObj->query("damage type") || "");

            // apply to
            string *applyToKeys = researchObj->query("apply to");
            mixed applyTo = ({});
            if (pointerp(applyToKeys))
            {
                applyTo = applyToKeys;
            }

            // affected research
            mapping affectedResearchData = researchObj->query("affected research");
            string affectedResearchType = (researchObj->query("affected research type") || "");
            mapping affectedResearch = ([]);
            if (mappingp(affectedResearchData))
            {
                affectedResearch = affectedResearchData;
            }

            // limiters
            mapping limiterData = researchObj->query("limited by");
            mapping limiters = ([]);
            if (mappingp(limiterData))
            {
                string *limiterKeys = m_indices(limiterData);
                foreach (string lk in limiterKeys)
                {
                    mixed lv = limiterData[lk];
                    // resolve research/trait file paths to names
                    if (lk == "research" || lk == "research active")
                    {
                        mixed *resolved = ({});
                        if (pointerp(lv))
                        {
                            foreach (string rpath in lv)
                            {
                                object rObj = getService("research")->researchObject(rpath);
                                resolved += ({ objectp(rObj) ? (rObj->query("name") || rpath) : rpath });
                            }
                        }
                        limiters[lk] = resolved;
                    }
                    else if (lk == "traits")
                    {
                        mixed *resolved = ({});
                        if (pointerp(lv))
                        {
                            foreach (string tpath in lv)
                            {
                                object tObj = getService("traits")->traitObject(tpath);
                                resolved += ({ objectp(tObj) ? (tObj->query("name") || tpath) : tpath });
                            }
                        }
                        limiters[lk] = resolved;
                    }
                    else
                    {
                        limiters[lk] = lv;
                    }
                }
            }

            // cost modifiers (research that reduces use cost)
            mapping costModData = researchObj->query("cost modifiers");
            mapping costModifiers = ([]);
            if (mappingp(costModData))
            {
                foreach (string rpath in m_indices(costModData))
                {
                    object rObj = getService("research")->researchObject(rpath);
                    string rName = objectp(rObj) ? (rObj->query("name") || rpath) : rpath;
                    costModifiers[rName] = costModData[rpath];
                }
            }

            // cooldown modifiers
            mapping cdModData = researchObj->query("cooldown modifiers");
            mapping cooldownModifiers = ([]);
            if (mappingp(cdModData))
            {
                foreach (string rpath in m_indices(cdModData))
                {
                    object rObj = getService("research")->researchObject(rpath);
                    string rName = objectp(rObj) ? (rObj->query("name") || rpath) : rpath;
                    cooldownModifiers[rName] = cdModData[rpath];
                }
            }

            // consumables
            mapping consumableData = researchObj->query("consumables");
            mapping consumables = ([]);
            if (mappingp(consumableData))
            {
                consumables = consumableData;
            }

            int supercede = (researchObj->query("supercede targets") || 0);

            string *bonusKeys = researchObj->query("bonuses");
            string *penaltyKeys = researchObj->query("penalties");
            mapping bonuses = ([]);
            mapping penalties = ([]);
            if (pointerp(bonusKeys))
            {
                foreach (string bk in bonusKeys)
                {
                    bonuses[bk] = researchObj->query(bk);
                }
            }
            if (pointerp(penaltyKeys))
            {
                foreach (string pk in penaltyKeys)
                {
                    penalties[pk] = researchObj->query(pk);
                }
            }

            nodes += ({ ([
                "path": nodePath,
                "name": (researchObj->query("name") || ""),
                "description": (researchObj->query("description") || ""),
                "type": (researchObj->query("research type") || ""),
                "researchType": (researchObj->query("type") || ""),
                "scope": (researchObj->query("scope") || ""),
                "effect": (researchObj->query("effect") || ""),
                "cost": (researchObj->query("research cost") || 0),
                "spellPointCost": (researchObj->query("spell point cost") || 0),
                "hitPointCost": (researchObj->query("hit point cost") || 0),
                "staminaPointCost": (researchObj->query("stamina point cost") || 0),
                "cooldown": (researchObj->query("cooldown") || 0),
                "duration": (researchObj->query("duration") || 0),
                "commandTemplate": (researchObj->query("command template") || ""),
                "status": nodeStatus,
                "parents": parents,
                "prerequisites": prereqs,
                "bonuses": bonuses,
                "penalties": penalties,
                "modifiers": modifiers,
                "damageEffects": damageEffects,
                "damageType": damageType,
                "applyTo": applyTo,
                "affectedResearch": affectedResearch,
                "affectedResearchType": affectedResearchType,
                "limiters": limiters,
                "costModifiers": costModifiers,
                "cooldownModifiers": cooldownModifiers,
                "consumables": consumables,
                "supercedeTargets": supercede
            ]) });
        }

        trees += ({ ([
            "name": (treeObj->Name() || ""),
            "source": (treeObj->Source() || ""),
            "root": (treeObj->TreeRoot() || ""),
            "nodes": nodes
        ]) });
    }

    return ([
        "points": player->researchPoints(),
        "trees": trees
    ]);
}

/////////////////////////////////////////////////////////////////////////////
public void pushVitals()
{
    if (objectp(player) && function_exists("sendOutOfBand", player) &&
        function_exists("hitPoints", player))
    {
        player->sendOutOfBand("Char.Vitals", vitalsSnapshot(player));
    }
}

/////////////////////////////////////////////////////////////////////////////
public void pushScore()
{
    if (objectp(player) && function_exists("sendOutOfBand", player) &&
        function_exists("hitPoints", player))
    {
        string level = player->isRealizationOf("wizard") ?
            capitalize(player->wizardLevel()) :
            to_string(player->effectiveLevel());

        mapping score = ([
            "name": player->RealName(),
            "title": player->Title(),
            "level": level,
            "experience": player->effectiveExperience(),
            "gender": (player->Gender() || "male"),
            "race": (player->Race() || ""),
            "guilds": guildsSnapshot(player),
            "attributes": attributesSnapshot(player),
            "vitals": vitalsSnapshot(player),
            "combat": combatSnapshot(player)
        ]);

        player->sendOutOfBand("Char.Score", score);
    }
}

/////////////////////////////////////////////////////////////////////////////
public void pushInventory()
{
    if (objectp(player) && function_exists("sendOutOfBand", player) &&
        function_exists("equipmentInSlot", player))
    {
        string *slots = ({ "armor", "cloak", "helmet", "amulet", "belt",
            "arm greaves", "leg greaves", "gloves", "bracers", "boots",
            "ring 1", "ring 2", "wielded primary", "wielded offhand" });

        mapping equipped = ([]);
        object *equippedObjects = ({});
        foreach (string slot in slots)
        {
            object item = player->equipmentInSlot(slot);
            if (objectp(item))
            {
                equipped[slot] = summarizeInventoryItem(item, slot);
                if (member(equippedObjects, item) < 0)
                {
                    equippedObjects += ({ item });
                }
            }
        }

        mixed carried = ({});
        object *allItems = filter(all_inventory(player),
            (: (member(inherit_list($1),
                    "/lib/items/modifierObject.c") < 0) &&
               (member(equippedObjects, $1) < 0) &&
               stringp($1->query("short")) :));

        foreach (object item in allItems)
        {
            carried += ({ summarizeInventoryItem(item, 0) });
        }

        player->sendOutOfBand("Char.Inventory", ([
            "equipped": equipped,
            "carried": carried
        ]));
    }
}

/////////////////////////////////////////////////////////////////////////////
public void pushSkills()
{
    if (objectp(player) && function_exists("sendOutOfBand", player) &&
        function_exists("getSkill", player))
    {
        player->sendOutOfBand("Char.Skills", skillsSnapshot(player));
    }
}

/////////////////////////////////////////////////////////////////////////////
public void pushTraits()
{
    if (objectp(player) && function_exists("sendOutOfBand", player) &&
        function_exists("Traits", player))
    {
        player->sendOutOfBand("Char.Traits", ([
            "traits": traitsSnapshot(player)
        ]));
    }
}

/////////////////////////////////////////////////////////////////////////////
public void pushResearchList()
{
    if (objectp(player) && function_exists("sendOutOfBand", player) &&
        function_exists("availableResearchTrees", player))
    {
        object researchService = getService("research");
        string *availableTrees = player->availableResearchTrees();
        if (!pointerp(availableTrees))
        {
            availableTrees = ({});
        }

        mixed trees = ({});
        foreach (string treePath in availableTrees)
        {
            object treeObj = researchService->researchTree(treePath);
            if (!objectp(treeObj))
            {
                continue;
            }
            trees += ({ ([
                "name":   (treeObj->Name()     || ""),
                "source": (treeObj->Source()   || ""),
                "root":   (treeObj->TreeRoot() || ""),
                "path":   treePath
            ]) });
        }

        player->sendOutOfBand("Char.Research.List", ([
            "trees": trees
        ]));
    }
}

/////////////////////////////////////////////////////////////////////////////
public void pushResearchTree(string treePath)
{
    if (!objectp(player) || !function_exists("sendOutOfBand", player))
    {
        return;
    }

    object researchService = getService("research");
    object treeObj = researchService->researchTree(treePath);
    if (!objectp(treeObj))
    {
        return;
    }

    mapping flatTree = treeObj->getFlattenedResearchTree(player);
    if (!mappingp(flatTree))
    {
        return;
    }

    mixed nodes = ({});
    object *nodeObjects = m_indices(flatTree);

    foreach (object researchObj in nodeObjects)
    {
        if (!objectp(researchObj))
        {
            continue;
        }

        string nodePath = program_name(researchObj);
        mapping statusData = flatTree[researchObj];

        string nodeStatus = "locked";
        if (mappingp(statusData))
        {
            if (member(statusData, "researched"))
            {
                nodeStatus = "known";
            }
            else if (member(statusData, "researching"))
            {
                nodeStatus = "in_progress";
            }
            else if (member(statusData, "can research"))
            {
                nodeStatus = "available";
            }
        }

        string *parents = treeObj->getParents(nodePath);
        if (!pointerp(parents))
        {
            parents = ({});
        }

        mixed prereqs = ({});
        mapping prereqMap = researchObj->getPrerequisites();
        if (mappingp(prereqMap))
        {
            foreach (string prereqKey in m_indices(prereqMap))
            {
                mapping pd = prereqMap[prereqKey];
                if (mappingp(pd))
                {
                    string prereqType = (pd["type"] || "");
                    string displayKey = prereqKey;
                    if (prereqType == "research")
                    {
                        object rObj = getService("research")->researchObject(prereqKey);
                        if (objectp(rObj))
                        {
                            displayKey = (rObj->query("name") || prereqKey);
                        }
                    }
                    prereqs += ({ ([
                        "key":   displayKey,
                        "type":  prereqType,
                        "value": (pd["value"] || 0),
                        "guild": (pd["guild"] || "")
                    ]) });
                }
            }
        }

        mixed *modifierData = researchObj->query("modifiers");
        mixed modifiers = ({});
        if (pointerp(modifierData))
        {
            foreach (mapping mod in modifierData)
            {
                if (mappingp(mod))
                {
                    modifiers += ({ ([
                        "type":    (mod["type"]    || ""),
                        "name":    (mod["name"]    || ""),
                        "formula": (mod["formula"] || ""),
                        "rate":    (mod["rate"]    || 0)
                    ]) });
                }
            }
        }

        string *effectTypes = ({
            "damage hit points", "damage spell points",
            "damage stamina points", "increase hit points",
            "increase spell points", "increase stamina points",
            "siphon hit points", "siphon spell points",
            "siphon stamina points"
        });
        mapping damageEffects = ([]);
        foreach (string effectType in effectTypes)
        {
            mixed *effectData = researchObj->query(effectType);
            if (pointerp(effectData) && sizeof(effectData))
            {
                mixed *entries = ({});
                foreach (mapping entry in effectData)
                {
                    if (mappingp(entry))
                    {
                        entries += ({ ([
                            "probability": (entry["probability"] || 0),
                            "baseDamage":  (entry["base damage"] || 0),
                            "range":       (entry["range"]       || 0)
                        ]) });
                    }
                }
                if (sizeof(entries))
                {
                    damageEffects[effectType] = entries;
                }
            }
        }

        string damageType = (researchObj->query("damage type") || "");

        string *applyToKeys = researchObj->query("apply to");
        mixed applyTo = pointerp(applyToKeys) ? applyToKeys : ({});

        mapping affectedResearchData = researchObj->query("affected research");
        mapping affectedResearch = mappingp(affectedResearchData) ? affectedResearchData : ([]);
        string affectedResearchType = (researchObj->query("affected research type") || "");

        mapping limiterData = researchObj->query("limited by");
        mapping limiters = ([]);
        if (mappingp(limiterData))
        {
            foreach (string lk in m_indices(limiterData))
            {
                mixed lv = limiterData[lk];
                if (lk == "research" || lk == "research active")
                {
                    mixed *resolved = ({});
                    if (pointerp(lv))
                    {
                        foreach (string rpath in lv)
                        {
                            object rObj = getService("research")->researchObject(rpath);
                            resolved += ({ objectp(rObj) ? (rObj->query("name") || rpath) : rpath });
                        }
                    }
                    limiters[lk] = resolved;
                }
                else if (lk == "traits")
                {
                    mixed *resolved = ({});
                    if (pointerp(lv))
                    {
                        foreach (string tpath in lv)
                        {
                            object tObj = getService("traits")->traitObject(tpath);
                            resolved += ({ objectp(tObj) ? (tObj->query("name") || tpath) : tpath });
                        }
                    }
                    limiters[lk] = resolved;
                }
                else
                {
                    limiters[lk] = lv;
                }
            }
        }

        mapping costModData = researchObj->query("cost modifiers");
        mapping costModifiers = ([]);
        if (mappingp(costModData))
        {
            foreach (string rpath in m_indices(costModData))
            {
                object rObj = getService("research")->researchObject(rpath);
                string rName = objectp(rObj) ? (rObj->query("name") || rpath) : rpath;
                costModifiers[rName] = costModData[rpath];
            }
        }

        mapping cdModData = researchObj->query("cooldown modifiers");
        mapping cooldownModifiers = ([]);
        if (mappingp(cdModData))
        {
            foreach (string rpath in m_indices(cdModData))
            {
                object rObj = getService("research")->researchObject(rpath);
                string rName = objectp(rObj) ? (rObj->query("name") || rpath) : rpath;
                cooldownModifiers[rName] = cdModData[rpath];
            }
        }

        mapping consumableData = researchObj->query("consumables");
        mapping consumables = mappingp(consumableData) ? consumableData : ([]);

        int supercede = (researchObj->query("supercede targets") || 0);

        string *bonusKeys   = researchObj->query("bonuses");
        string *penaltyKeys = researchObj->query("penalties");
        mapping bonuses   = ([]);
        mapping penalties = ([]);
        if (pointerp(bonusKeys))
        {
            foreach (string bk in bonusKeys)
            {
                bonuses[bk] = researchObj->query(bk);
            }
        }
        if (pointerp(penaltyKeys))
        {
            foreach (string pk in penaltyKeys)
            {
                penalties[pk] = researchObj->query(pk);
            }
        }

        nodes += ({ ([
            "path":               nodePath,
            "name":               (researchObj->query("name")             || ""),
            "description":        (researchObj->query("description")      || ""),
            "type":               (researchObj->query("research type")    || ""),
            "researchType":       (researchObj->query("type")             || ""),
            "scope":              (researchObj->query("scope")            || ""),
            "effect":             (researchObj->query("effect")           || ""),
            "cost":               (researchObj->query("research cost")    || 0),
            "spellPointCost":     (researchObj->query("spell point cost") || 0),
            "hitPointCost":       (researchObj->query("hit point cost")   || 0),
            "staminaPointCost":   (researchObj->query("stamina point cost") || 0),
            "cooldown":           (researchObj->query("cooldown")         || 0),
            "duration":           (researchObj->query("duration")         || 0),
            "commandTemplate":    (researchObj->query("command template") || ""),
            "status":             nodeStatus,
            "parents":            parents,
            "prerequisites":      prereqs,
            "bonuses":            bonuses,
            "penalties":          penalties,
            "modifiers":          modifiers,
            "damageEffects":      damageEffects,
            "damageType":         damageType,
            "applyTo":            applyTo,
            "affectedResearch":   affectedResearch,
            "affectedResearchType": affectedResearchType,
            "limiters":           limiters,
            "costModifiers":      costModifiers,
            "cooldownModifiers":  cooldownModifiers,
            "consumables":        consumables,
            "supercedeTargets":   supercede
        ]) });
    }

    player->sendOutOfBand("Char.Research.Tree", ([
        "name":   (treeObj->Name()     || ""),
        "source": (treeObj->Source()   || ""),
        "root":   (treeObj->TreeRoot() || ""),
        "nodes":  nodes
    ]));

    player->sendOutOfBand("Char.Research.Done", ([
        "points": player->researchPoints()
    ]));
}

/////////////////////////////////////////////////////////////////////////////
public void pushResearch()
{
    if (objectp(player) && function_exists("sendOutOfBand", player) &&
        function_exists("completedResearch", player))
    {
        mapping snapshot = researchSnapshot(player);
        mixed trees = snapshot["trees"];

        if (pointerp(trees))
        {
            foreach (mapping tree in trees)
            {
                player->sendOutOfBand("Char.Research.Tree", tree);
            }
        }

        player->sendOutOfBand("Char.Research.Done", ([
            "points": snapshot["points"]
        ]));
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onHitPointsChanged(object caller, mixed data)
{
    if (objectp(caller) && caller == player)
    {
        pushVitals();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onSpellPointsChanged(object caller, mixed data)
{
    if (objectp(caller) && caller == player)
    {
        pushVitals();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onStaminaPointsChanged(object caller, mixed data)
{
    if (objectp(caller) && caller == player)
    {
        pushVitals();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onEquip(object caller, mixed data)
{
    if (objectp(caller) && caller == player)
    {
        pushScore();
        pushInventory();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onUnequip(object caller, mixed data)
{
    if (objectp(caller) && caller == player)
    {
        pushScore();
        pushInventory();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onRegisterItem(object caller, mixed data)
{
    if (objectp(caller) && caller == player)
    {
        pushInventory();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onUnregisterItem(object caller, mixed data)
{
    if (objectp(caller) && caller == player)
    {
        pushInventory();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onAdvancedLevel(object caller, mixed data)
{
    if (objectp(caller) && caller == player)
    {
        pushScore();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onAdvancedRank(object caller, mixed data)
{
    if (objectp(caller) && caller == player)
    {
        pushScore();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onDemotedRank(object caller, mixed data)
{
    if (objectp(caller) && caller == player)
    {
        pushScore();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onJoinGuild(object caller, mixed data)
{
    if (objectp(caller) && caller == player)
    {
        pushScore();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onLeaveGuild(object caller, mixed data)
{
    if (objectp(caller) && caller == player)
    {
        pushScore();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onRecalculating(object caller, mixed data)
{
    if (objectp(caller) && caller == player)
    {
        pushScore();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onSkillAdvanced(object caller, mixed data)
{
    if (objectp(caller) && caller == player)
    {
        pushScore();
        pushSkills();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onTraitAdded(object caller, mixed data)
{
    if (objectp(caller) && caller == player)
    {
        pushScore();
        pushTraits();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onTraitRemoved(object caller, mixed data)
{
    if (objectp(caller) && caller == player)
    {
        pushScore();
        pushTraits();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onResearchCompleted(object caller, mixed data)
{
    if (objectp(caller) && caller == player)
    {
        pushResearch();
        pushScore();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onResearchStarted(object caller, mixed data)
{
    if (objectp(caller) && caller == player)
    {
        pushResearch();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onResearchPointsAdded(object caller, mixed data)
{
    if (objectp(caller) && caller == player)
    {
        pushResearch();
        pushScore();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onResearchTreeOpen(object caller, mixed data)
{
    if (objectp(caller) && caller == player)
    {
        pushResearch();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void pushAll()
{
    pushScore();
    pushVitals();
    pushInventory();
    pushSkills();
    pushTraits();
    pushResearch();
}
