//*****************************************************************************
// Class: prerequisites
// File Name: prerequisites.c
//
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
// Description: This class is used to handle prerequisites. It is primarily
//              of interest for the lib's add-on modules, though it can
//              certainly be of use to any class that needs to limit its use,
//              entry, and so on based on an interactive object's data/state.
//
//*****************************************************************************

// This shows the blueprint for how prerequisites must be built.
protected mapping prerequisites = ([
// <key>: ([
//     "type": one of the items in the isValidPrerequisiteType array,
//     "value": optional value
// ]),
// Examples:
// "level": ([
//     "type": "level",
//     "guild": "mage", // This is an optional parameter.
//     "value": 10
// ]),
// "elemental fire": ([
//     "type": "skill",
//     "value": 15
// ]),
// "fetch a spatula": ([
//     "type": "quest",
// ]),
// "fire spells": ([
//     "type": "research"
// ]),
// "race": ([
//     "type": "race",
//     "value": ({ "elf", "half elf" })
// ]),
// "guild": ([
//     "type": "guild",
//     "value": ({ "fighter" })
// ]),
// "guild rank": ([
//     "type": "guild rank",
//     "guild": "mage",
//     "value": ({ "acolyte", "archmage" })
// ]),
// "best kill": ([
//     "type": "combat statistic",
//     "value": 45
// ]),
// "elf": ([
//     "type": "combat statistic",
//     "value": 100   // number of kills of creatures of this race
// ]),
// "trait": ([
//     "type": "trait",
//     "value": ({ "boorish", "loutish" })
// ])
]);

//-----------------------------------------------------------------------------
// Method: isValidPrerequisiteType
// Description: This method will return true if the supplied prerequisite type
//              is valid.
//
// Parameters: type - the prerequisite type to check
//
// Returns: true if the prerequisite type is valid.
//-----------------------------------------------------------------------------
private nomask int isValidPrerequisiteType(string type)
{
    return (member(({ "research", "attribute", "skill", "quest", "guild",
        "race", "faction", "trait", "background", "combat statistic", "level",
        "opinion", "state", "presence", "not present", "guild rank",
        "spoken topics" }), type) > -1);
}

//-----------------------------------------------------------------------------
// Method: validPrerequisite
// Description: This method will return true if the supplied prerequisite
//              mapping is in the proper format and is of a valid type.
//
// Parameters: prerequisite - the prerequisite to check
//
// Returns: true if the prerequisite is of valid format.
//-----------------------------------------------------------------------------
protected nomask int validPrerequisite(mapping prerequisite)
{
    return (prerequisite && mappingp(prerequisite) &&
            member(prerequisite, "type") && 
            isValidPrerequisiteType(prerequisite["type"]));
}

//-----------------------------------------------------------------------------
// Method: getPrerequisite
// Description: This method will return the details mapping for the requested
//              prerequisite if it exists.
//
// Parameters: prerequisite - the prerequisite to retrieve
//
// Returns: the details mapping for the specified prerequisite.
//-----------------------------------------------------------------------------   
private nomask mapping getPrerequisite(string prerequisite, string grouping)
{
    mapping ret = 0;

    if (grouping && member(prerequisites, grouping) &&
        member(prerequisites[grouping], prerequisite) &&
        validPrerequisite(prerequisites[grouping][prerequisite]))
    {
        ret = prerequisites[grouping][prerequisite] + ([]);
    }
    else if(member(prerequisites, prerequisite) &&
       validPrerequisite(prerequisites[prerequisite]))
    {
        ret = prerequisites[prerequisite] + ([ ]);
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: getPrerequisites
// Description: This method will return all of the prerequisites for this
//              object.
//
// Returns: the prerequisites mapping
//----------------------------------------------------------------------------- 
public nomask mapping getPrerequisites()
{
    return prerequisites + ([ ]);
}

//-----------------------------------------------------------------------------
// Method: addPrerequisite
// Description: This method will add the supplied prerequisite details for the
//              given key provided that it is in the valid prerequisite
//              format and the supplied key does not already exist. This method
//              can only be accessed by objects that inherit it.
//
// Parameters: key - the key/name of the prerequisite
//             prerequisite - the prerequisite details mapping
//
// Returns: true if the prerequisite has been added
//-----------------------------------------------------------------------------  
protected nomask varargs int addPrerequisite(string key, mapping prerequisite, 
    string grouping)
{
    int ret = 0;

    if (grouping && stringp(grouping) && key && stringp(key) && 
        validPrerequisite(prerequisite) && (!member(prerequisites, grouping) ||
        (member(prerequisites, grouping) && !member(prerequisites[grouping], key))))
    {
        if (!member(prerequisites, grouping))
        {
            prerequisites[grouping] = ([]);
        }
        prerequisites[grouping] += ([key:prerequisite]);
        ret = 1;
    }
    else if(!grouping && key && stringp(key) && validPrerequisite(prerequisite) &&
       !member(prerequisites, key))
    {
        prerequisites[key] = prerequisite + ([ ]);
        ret = 1;
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: validResearcher
// Description: This method will return true if the object passed inherits
//              the research module.
//
// Parameters: researcher - the object to check
//
// Returns: true if the researcher object is of type 'research'
//-----------------------------------------------------------------------------
private nomask int validResearcher(object researcher)
{
    return (researcher && objectp(researcher) && researcher->has("research"));
}

//-----------------------------------------------------------------------------
// Method: checkResearch
// Description: This method will check whether or not the passed researcher
//              has researched the item identified by the passed 'research' 
//              key.
//
// Parameters: researcher - the object to check
//             research - the research item to verify knowledge of
//
// Returns: true if the researcher object 'knows' the passed research topic
//-----------------------------------------------------------------------------
private nomask int checkResearch(object researcher, string research)
{
    return (validResearcher(researcher) && researcher->has("research") &&
        (researcher->isResearched(research) || 
            researcher->equivalentIsResearched(research)));
}

//-----------------------------------------------------------------------------
// Method: checkAttribute
// Description: This method will check whether or not the passed researcher
//              has an 'attribute' attribute of at least the passed value.
//
// Parameters: researcher - the object to check
//             attribute - the attribute to check
//             value - the minimum value of the attribute
//
// Returns: true if the researcher object has attribute of at least the
//          specified value.
//-----------------------------------------------------------------------------
private nomask int checkAttribute(object researcher, string attribute, 
    int value)
{
    return (validResearcher(researcher) && researcher->has("attributes") &&
        (researcher->attributeValue(attribute) >= value));
}

//-----------------------------------------------------------------------------
// Method: checkSkill
// Description: This method will check whether or not the passed researcher
//              has a 'skill' skill of at least the passed value.
//
// Parameters: researcher - the object to check
//             skill - the skill to check
//             value - the minimum value of the skill
//
// Returns: true if the researcher object has skill of at least the
//          specified value.
//-----------------------------------------------------------------------------
private nomask int checkSkill(object researcher, string skill, int value)
{
    return (validResearcher(researcher) && researcher->has("skills") &&
        (researcher->getSkill(skill) >= value));
}

//-----------------------------------------------------------------------------
// Method: checkLevel
// Description: This method will check whether or not the passed researcher
//              is of at least the specified level. If the optional guild
//              argument is passed, it will check the level of that guild.
//              Otherwise, the passed in object's effective level is checked
//
// Parameters: researcher - the object to check
//             level - the minimum level of the researcher
//             guild - Optional. The guild to check the researcher's level in
//
// Returns: true if the researcher object is of at least the specified level
//-----------------------------------------------------------------------------
private nomask varargs int checkLevel(object researcher, int level, string guild)
{
    int ret = validResearcher(researcher) && researcher->has("guilds");
    if(ret)
    {
        if(guild && stringp(guild) && researcher->memberOfGuild(guild))
        {
            ret &&= researcher->guildLevel(guild) >= level;
        }
        else
        {
            ret &&= researcher->effectiveLevel() >= level;
        }
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: checkQuest
// Description: This method will check whether or not the passed researcher
//              has completed the passed quest.
//
// Parameters: researcher - the object to check
//             quest - the quest to check if completed
//
// Returns: true if the researcher object has completed the passed quest
//-----------------------------------------------------------------------------    
private nomask int checkQuest(object researcher, string quest)
{
    return (validResearcher(researcher) && researcher->has("quests") &&
        researcher->questIsCompleted(quest));
}

//-----------------------------------------------------------------------------
// Method: checkGuilds
// Description: This method will check whether or not the passed researcher
//              is a member of one of the passed guilds
//
// Parameters: researcher - the object to check
//             guilds - an array of valid guilds to check membership of
//
// Returns: true if the researcher object is a member of at least one of the
//          specified guilds.
//-----------------------------------------------------------------------------
private nomask int checkGuilds(object researcher, string *guilds)
{
    int ret = 0;
    if(validResearcher(researcher) && researcher->has("guilds") &&
       pointerp(guilds))
    {
        ret = 1;
        int inGuild = 0;
        foreach(string guild in guilds)
        {
            inGuild ||= researcher->memberOfGuild(guild);
        }
        ret &&= inGuild;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkGuildRanks(object researcher, string guild,
    string *ranks)
{
    return checkGuilds(researcher, ({ guild })) && pointerp(ranks) &&
        (member(ranks, researcher->guildRank(guild)) > -1);
}

//-----------------------------------------------------------------------------
// Method: checkRaces
// Description: This method will check whether or not the passed researcher
//              is a member of one of the passed races
//
// Parameters: researcher - the object to check
//             guilds - an array of valid races to check membership of
//
// Returns: true if the researcher object is a member of one of the specified
//          races.
//-----------------------------------------------------------------------------
private nomask int checkRaces(object researcher, string *races)
{
    int ret = 0;
    if(validResearcher(researcher) && researcher->has("races") &&
       pointerp(races))
    {
        ret = 1;
        int ofRace = 0;
        foreach(string race in races)
        {
            ofRace ||= researcher->Race() == race;
        }
        ret &&= ofRace;
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: checkFactions
// Description: This method will check whether or not the passed researcher
//              is a member of one of the passed factions
//
// Parameters: researcher - the object to check
//             factions - an array of valid factions to check membership of
//
// Returns: true if the researcher object is a member of at least one of the
//          specified factions.
//-----------------------------------------------------------------------------
private nomask int checkFactions(object researcher, string *factions)
{
    int ret = 0;
    if(validResearcher(researcher) && researcher->has("factions") &&
       pointerp(factions))
    {
        ret = 1;
        int ofFaction = 0;
        foreach(string faction in factions)
        {
            ofFaction ||= researcher->memberOfFaction(faction);
        }
        ret &&= ofFaction;
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: checkTraits
// Description: This method will check whether or not the passed researcher
//              has at least one of the passed traits
//
// Parameters: researcher - the object to check
//             traits - an array of valid traits
//
// Returns: true if the researcher object has at least one of the specified
//          traits.
//-----------------------------------------------------------------------------
private nomask int checkTraits(object researcher, string *traits)
{
    int ret = 0;
    if(validResearcher(researcher) && researcher->has("traits") &&
       pointerp(traits))
    {
        ret = 1;
        int hasTrait = 0;
        foreach(string trait in traits)
        {
            hasTrait ||= researcher->isTraitOf(trait);
        }
        ret &&= hasTrait;
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: checkBackground
// Description: This method will check whether or not the passed researcher
//              has at least one of the passed backgrounds
//
// Parameters: researcher - the object to check
//             backgrounds - an array of valid backgrounds to check
//
// Returns: true if the researcher object has at least one of the specified
//          backgrounds.
//-----------------------------------------------------------------------------
private nomask int checkBackground(object researcher, string *backgrounds)
{
    int ret = 0;
    if(validResearcher(researcher) && researcher->has("background") &&
       pointerp(backgrounds))
    {
        ret = 1;
        int hasBackground = 0;
        foreach(string background in backgrounds)
        {
            hasBackground ||= researcher->isBackgroundTraitOf(background);
        }
        ret &&= hasBackground;
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: checkCombatStats
// Description: This method will check whether or not the passed researcher
//              has a 'type' combat statistic of at least the passed value.
//              Only "best kill" and "race" are valid.
//
// Parameters: researcher - the object to check
//             type - the combat statistic to check - "best kill" or "race"
//             value - the minimum value of the statistic
//
// Returns: true if the researcher object has combat statistics of the given
//          type of at least the specified value.
//-----------------------------------------------------------------------------
private nomask int checkCombatStats(object researcher, string type, int value)
{
    // Only two types are supported: "best kill" which is the level of the best
    // kill or "race". If the prereq is NOT "best kill" it will be interpreted
    // as the number of kills of a certain race.
    int ret = 0;
    if(validResearcher(researcher) && researcher->has("combat"))
    {
        if(type && stringp(type))
        {
            switch(type)
            {
                case "best kill":
                {
                    ret = researcher->bestKillMeetsLevel(value);
                    break;
                }
                default:
                {
                    ret = researcher->racialKillsMeetCount(type, value);
                    break;
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkPresence(object researcher, string *characters)
{
    int ret = 0;
    if (sizeof(characters))
    {
        object location = environment(researcher);
        ret = objectp(location);

        foreach(string character in characters)
        {
            ret &&= objectp(present(character, location));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkSpokenTopics(object researcher, object checker,
    string *topics)
{
    int ret = sizeof(topics) && objectp(checker);

    if (ret)
    {
        foreach(string topic in topics)
        {
            ret &&= checker->userHasHadConversation(researcher->RealName(), 
                topic);
        }
    }

    return ret;
}

//-----------------------------------------------------------------------------
// Method: checkPrerequisites
// Description: This method will check whether or not the passed researcher
//              has passed all of the requirements and will return true if this
//              is the case.
//
// Parameters: researcher - the object to check
//
// Returns: true if the researcher object has passed all of the prerequisites.
//-----------------------------------------------------------------------------                        
public nomask varargs int checkPrerequisites(object researcher, string grouping, 
    object owner)
{
    int ret = 1;
    
    string *prerequisiteList = (grouping && member(prerequisites, grouping)) ?
        m_indices(prerequisites[grouping]) : m_indices(prerequisites);

    if(sizeof(prerequisiteList))
    {
        foreach(string prerequisite in prerequisiteList)
        {
            mapping prerequisiteData = getPrerequisite(prerequisite, grouping);
            if (prerequisiteData)
            {
                switch (prerequisiteData["type"])
                {
                    case "research":
                    {
                        // This should NOT be used to handle prerequisites
                        // that would exist within a single research tree
                        // structure.
                        ret &&= checkResearch(researcher, prerequisite);
                        break;
                    }
                    case "attribute":
                    {
                        ret &&= checkAttribute(researcher, prerequisite,
                            prerequisiteData["value"]);
                        break;
                    }
                    case "skill":
                    {
                        ret &&= checkSkill(researcher, prerequisite,
                            prerequisiteData["value"]);
                        break;
                    }
                    case "quest":
                    {
                        ret &&= checkQuest(researcher, prerequisite);
                        break;
                    }
                    case "guild":
                    {
                        ret &&= checkGuilds(researcher, prerequisiteData["value"]);
                        break;
                    }
                    case "guild rank":
                    {
                        ret &&= checkGuildRanks(researcher, 
                            prerequisiteData["guild"], prerequisiteData["value"]);
                        break;
                    }
                    case "race":
                    {
                        ret &&= checkRaces(researcher, prerequisiteData["value"]);
                        break;
                    }
                    case "faction":
                    {
                        ret &&= checkFactions(researcher, prerequisiteData["value"]);
                        break;
                    }
                    case "trait":
                    {
                        ret &&= checkTraits(researcher, prerequisiteData["value"]);
                        break;
                    }
                    case "background":
                    {
                        ret &&= checkBackground(researcher, prerequisiteData["value"]);
                        break;
                    }
                    case "level":
                    {
                        ret &&= (member(prerequisiteData, "guild") ?
                            checkLevel(researcher, prerequisiteData["value"],
                                prerequisiteData["guild"]) :
                            checkLevel(researcher, prerequisiteData["value"]));
                        break;
                    }
                    case "combat statistic":
                    {
                        ret &&= checkCombatStats(researcher, prerequisite,
                            prerequisiteData["value"]);
                        break;
                    }
                    case "opinion":
                    {
                        ret &&= owner && (owner->opinionOf(researcher) >=
                            prerequisiteData["value"]);
                        break;
                    }
                    case "state":
                    {
                        ret &&= researcher && member(prerequisiteData, "state key") &&
                            (researcher->stateFor(load_object(prerequisiteData["state key"])) ==
                            prerequisiteData["value"]);
                        break;
                    }
                    case "presence":
                    {
                        ret &&= checkPresence(researcher, prerequisiteData["value"]);
                        break;
                    }
                    case "not present":
                    {
                        ret &&= !checkPresence(researcher, prerequisiteData["value"]);
                        break;
                    }
                    case "spoken topics":
                    {
                        ret &&= checkSpokenTopics(researcher, owner, 
                            prerequisiteData["value"]);
                        break;
                    }
                    default:
                    {
                        ret = 0;
                        break;
                    }
                }
            }
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayResearchPrerequsite(string item)
{
    string ret = "";

    object dictionary = load_object("/lib/dictionaries/researchDictionary.c");
    if (dictionary)
    {
        object research = dictionary->researchObject(item);
        if (research)
        {
            ret = capitalizeAllWords(research->query("name"));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayQuestPrerequsite(string item)
{
    string ret = "";

    object dictionary = load_object("/lib/dictionaries/questsDictionary.c");
    if (dictionary)
    {
        ret = dictionary->questSummary(item);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayTraitPrerequsite(string *traits)
{
    string ret = "";

    object dictionary = load_object("/lib/dictionaries/traitsDictionary.c");
    if (dictionary && sizeof(traits))
    {
        foreach(string trait in traits)
        {
            object traitObj = dictionary->traitObject(trait);
            if (traitObj)
            {
                ret += capitalize(traitObj->query("name")) + " or ";
            }
        }
        ret = ret[..(sizeof(ret) - 5)];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string displayPrerequisites(string colorConfiguration, 
    object configuration)
{
    string ret = "";

    if (sizeof(prerequisites) && objectp(configuration))
    {
        ret = configuration->decorate("Prerequisites:\n",
            "field header", "research", colorConfiguration);

        string *prereqKeys = sort_array(m_indices(prerequisites), 
            (: (($3[$1]["type"] > $3[$2]["type"]) && ($1 > $2)) :), prerequisites);

        foreach(string key in prereqKeys)
        {
            string prereq = "";
            string supplementalInfo = 0;
            switch (prerequisites[key]["type"])
            {
                case "quest":
                {
                    prereq = displayQuestPrerequsite(key);
                    break;
                }
                case "research":
                {
                    prereq = displayResearchPrerequsite(key);
                    
                    string *equivalent = 
                        getDictionary("research")->equivalentItems(key);
                    if (sizeof(equivalent))
                    {
                        supplementalInfo = "";
                        foreach(string item in equivalent)
                        {
                            if (sizeof(item) > 50)
                            {
                                item = item[0..46] + "...";
                            }

                            supplementalInfo += 
                                configuration->decorate(
                                    sprintf("%17sEquivalent: ", ""),
                                    "prerequisite", "research", colorConfiguration) +
                                configuration->decorate(item + "\n",
                                    "equivalent", "research", colorConfiguration);
                        }
                    }
                    break;
                }
                case "trait":
                {
                    prereq = displayTraitPrerequsite(prerequisites[key]["value"]);
                    break;
                }
                case "attribute":
                case "level":
                case "opinion":
                case "skill":
                {
                    prereq = sprintf("%s of %d", capitalize(key), 
                        prerequisites[key]["value"]);
                    if (member(prerequisites[key], "guild"))
                    {
                        prereq += " in " + capitalize(prerequisites[key]["guild"]);
                    }
                    break;
                }
                case "combat statistic":
                {
                    prereq = sprintf("%s %s %d", capitalize(key),
                        (key == "best kill") ? "level is" : "kill count of",
                        prerequisites[key]["value"]);
                    break;
                }
                case "guild rank":
                {
                    prereq = sprintf("Rank in the %s guild of ", 
                        prerequisites[key]["guild"]);
                    // Yes, fall through! 
                }
                case "guild":
                case "race":
                case "presence":
                case "not present":
                case "faction":
                {
                    if (pointerp(prerequisites[key]["value"]) &&
                        sizeof(prerequisites[key]["value"]))
                    {
                        string *words = explode(implode(
                            prerequisites[key]["value"], " or "), " ");

                        int size = sizeof(words);
                        for (int i = 0; i < size; i++)
                        {
                            if (words[i] != "or")
                            {
                                words[i] = capitalize(words[i]);
                            }
                        }

                        prereq += implode(words, " ");
                    }
                    break;
                }
            }

            if (sizeof(prereq) > 62)
            {
                prereq = prereq[0..58] + "...";
            }

            ret += configuration->decorate(sprintf("%15s: ",
                        capitalize(prerequisites[key]["type"])),
                    "field data", "research", colorConfiguration) +
                configuration->decorate(prereq + "\n",
                    "prerequisite", "research", colorConfiguration);

            if (supplementalInfo)
            {
                ret += supplementalInfo;
            }
        }
    }
    return ret;
}
