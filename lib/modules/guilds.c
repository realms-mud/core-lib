//*****************************************************************************
// Class: guilds
// File Name: guilds.c
//
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/organizations.c";
#include "/lib/modules/secure/guilds.h"

private int SuppressLevelUpMessage = 0;

//-----------------------------------------------------------------------------
// Method: validGuildModifiers
// Description: The valid* methods are admittedly a bit of a misnomer. The real
//              intent is to list all of the calculated bonuses used in combat
//              that are controlled by this object. It is only accessible
//              within the inheritance tree.
//
// Returns: the list of bonus methods controlled by this object
//-----------------------------------------------------------------------------
static nomask string *validGuildModifiers()
{
    return ({ "bonus reduce spell points", "bonus recover spell points",
              "bonus reduce stamina points", "bonus recover stamina points" });
}

/////////////////////////////////////////////////////////////////////////////
private nomask object guildsDictionary()
{
    return getDictionary("guilds");
}

/////////////////////////////////////////////////////////////////////////////
static nomask string *validGuild()
{
    return guildsDictionary()->validGuilds() + ({ });
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int effectiveLevel(int onlyShowCombatGuilds)
{
    int ret = 0;
   
    if (!sizeof(guilds))
    {
        ret = 1;
    }
    else
    {
        foreach(string guild in m_indices(guilds))
        {
            if (!onlyShowCombatGuilds || (onlyShowCombatGuilds &&
                !guildsDictionary()->isNonCombatGuild(guild)))
            {
                ret += guilds[guild]["level"];
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int memberOfGuild(string guild, int onlyListCombatGuilds)
{
    return(guild && stringp(guild) && member(guilds, guild) && 
           mappingp(guilds[guild]) && member(guilds[guild], "level") &&
           member(guilds[guild], "experience") && 
           member(guilds[guild], "rank") &&
           !member(guilds[guild], "left guild") &&
           (!onlyListCombatGuilds || (onlyListCombatGuilds &&
           !guildsDictionary()->isNonCombatGuild(guild))));
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string *memberOfGuilds(int onlyListCombatGuilds)
{
    string *ret = ({ });
    if(sizeof(guilds))
    {
        ret = filter(m_indices(guilds), #'memberOfGuild, onlyListCombatGuilds);
    }
    return ret + ({ });
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string primaryGuild()
{
    string ret = this_object()->primaryGuildSetting();
    if (!ret)
    {
        ret = "guildless";

        string *guilds = memberOfGuilds();
        if (sizeof(guilds))
        {
            ret = guilds[0];
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int guildLevel(string guild)
{
    int ret = 0;
    if(memberOfGuild(guild) && intp(guilds[guild]["level"]))
    {
        ret = guilds[guild]["level"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int effectiveExperience()
{
    int ret = unassignedExperience;

    if (sizeof(guilds))
    {
        foreach(string guild in m_indices(guilds))
        {
            int level = guildLevel(guild);
            ret += 1000 * level * (level - 1) / 2 + guilds[guild]["experience"];
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int experienceToNextLevel(string guild)
{
    int ret = 1;
    if (memberOfGuild(guild) && intp(guilds[guild]["experience"]))
    {
        ret = guildsDictionary()->experienceToNextLevel(guild, guildLevel(guild)) -
        ((guilds[guild]["experience"] > 0) ? guilds[guild]["experience"] : 0);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int guildExperience(string guild)
{
    int ret = 0;
    if(memberOfGuild(guild) && intp(guilds[guild]["experience"]))
    {
        ret = guilds[guild]["experience"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addExperienceToGuild(int amount, string guild)
{
    int newExperienceAmount = guilds[guild]["experience"] + amount;
    int maxExp = 2 * guildsDictionary()->experienceToNextLevel(guild, guildLevel(guild));
    if (newExperienceAmount > maxExp)
    {
        guilds[guild]["experience"] = maxExp;
    }
    else
    {
        guilds[guild]["experience"] = newExperienceAmount;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void clearLevelUpSuppression()
{
    SuppressLevelUpMessage = 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int addExperience(int amount, string selectedGuild, 
    int ignorePartyCalculation)
{
    int ret = 0;
    int displayMessage = 0;

    object party = getService("parties") ? 
        getService("parties")->getParty() : 0;
    if (party && !ignorePartyCalculation)
    {
        amount = party->reallocateExperience(amount, selectedGuild, 
            this_object());
    }

    if (selectedGuild && member(guilds, selectedGuild))
    {
        addExperienceToGuild(amount, selectedGuild);

        if (experienceToNextLevel(selectedGuild) <= 0)
        {
            displayMessage = 1;
        }
        ret = amount;
    }
    else if (sizeof(guilds))
    {
        amount += unassignedExperience;
        unassignedExperience = 0;
        float guildLevels = to_float(effectiveLevel(1));
        foreach(string guild in memberOfGuilds(1))
        {
            // Since to_int truncates, the 0.5 is added to handle rounding issues.
            addExperienceToGuild(to_int(0.5 + amount *
                (guildLevel(guild) / (guildLevels > 0 ? guildLevels : 1))), guild);

            if (experienceToNextLevel(guild) <= 0)
            {
                displayMessage ||= 1;
            }
        }
        ret = amount;
    }
    else
    {
        unassignedExperience += amount;
        ret = unassignedExperience;
    }

    if (displayMessage && !SuppressLevelUpMessage)
    {
        string colorConfiguration = "none";
        object settings = getService("settings");
        if (objectp(settings))
        {
            colorConfiguration = settings->colorConfiguration();
        }

        tell_object(this_object(), getDictionary("configuration")->decorate(
            "You have enough experience to level up.\n",
            "level up", "score", colorConfiguration));
        SuppressLevelUpMessage = 1;
        call_out("clearLevelUpSuppression", 30);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int distributeExperience(int amount, 
    string *potentialGuilds)
{
    int ret = 0;
    string *availableGuilds = filter(memberOfGuilds(),
        (: (pointerp($2) && (member($2, $1) > -1)) :), potentialGuilds);

    if (sizeof(availableGuilds))
    {
        int expPerGuild = amount / sizeof(availableGuilds);
        foreach(string guild in availableGuilds)
        {
            ret += addExperience(expPerGuild, guild, 1);
        }
    }
    else
    {
        ret = addExperience(amount);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string guildRank(string guild)
{
    string ret = 0;
    if(memberOfGuild(guild) && stringp(guilds[guild]["rank"]))
    {
        ret = guilds[guild]["rank"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string guildRankName(string guild)
{
    string ret = 0;
    if(memberOfGuild(guild) && stringp(guilds[guild]["rank"]))
    {
        ret = guildsDictionary()->rankName(guild,
            guildRank(guild));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string guildTitle(string guild)
{
    string ret = 0;
    if(memberOfGuild(guild) && stringp(guilds[guild]["title"]))
    {
        ret = guilds[guild]["title"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string guildPretitle(string guild)
{
    string ret = 0;
    if(memberOfGuild(guild) && stringp(guilds[guild]["pretitle"]))
    {
        ret = guilds[guild]["pretitle"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void refreshCachedPartyDetails()
{
    object parties = getService("parties");
    if (parties)
    {
        object party = parties->getParty();
        if (party)
        {
            party->refresh();
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int advanceLevel(string guild)
{
    int ret = 0;
    if(memberOfGuild(guild) && guildsDictionary()->canAdvanceLevel(
       this_object(), guild))
    {
        // We can't just increment - this does processing for adding any
        // granted research, traits, skills, etc.
        guilds[guild]["level"] = guildsDictionary()->advanceLevel(
            this_object(), guild);

        // canAdvanceLevel will ensure that experience >= experienceToNextLevel
        guilds[guild]["experience"] = guilds[guild]["experience"] -
            guildsDictionary()->experienceToNextLevel(guild, guilds[guild]["level"] - 1);

        guilds[guild]["title"] = guildsDictionary()->title(guild, 
            guilds[guild]["level"], guilds[guild]["rank"]);
        guilds[guild]["pretitle"] = guildsDictionary()->pretitle(guild, 
            guilds[guild]["level"], guilds[guild]["rank"]);

        object state = getService("state");
        if (state)
        {
            state->resetCaches();
        }
        refreshCachedPartyDetails();

        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isAnathema(string guild)
{
    int ret = 0;
    if(guild && stringp(guild) && member(guilds, guild) &&
       member(guilds[guild], "anathema") &&
       intp(guilds[guild]["anathema"]))
    {
        object materialAttributes = getService("materialAttributes");
        if(materialAttributes && objectp(materialAttributes))
        {
            ret = materialAttributes->Age() < guilds[guild]["anathema"];
            if(!ret)
            {
                m_delete(guilds[guild], "anathema");
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int ageWhenRankAdvanced(string guild)
{
    int ret = 0;
    if(memberOfGuild(guild))
    {
        ret = guilds[guild]["rank advanced at"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void persistChanges()
{
    object persistence = getService("/secure/persistence");
    if (persistence)
    {
        persistence->save();
    }

    object state = getService("state");
    if (state)
    {
        state->resetCaches();
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int advanceRank(string guild)
{
    int ret = 0;
    if(memberOfGuild(guild) && guildsDictionary()->canAdvanceRank(
       this_object(), guild, guilds[guild]["rank"]) && !isAnathema(guild))
    {
        guilds[guild]["rank"] = guildsDictionary()->advanceRank(this_object(),
            guild, guilds[guild]["rank"]);
        guilds[guild]["title"] = guildsDictionary()->title(guild, 
            guilds[guild]["level"], guilds[guild]["rank"]);
        guilds[guild]["pretitle"] = guildsDictionary()->pretitle(guild, 
            guilds[guild]["level"], guilds[guild]["rank"]);

        object materialAttributes = getService("materialAttributes");
        if(materialAttributes && objectp(materialAttributes))
        {
            guilds[guild]["rank advanced at"] = materialAttributes->Age();
        }
        
        object events = getService("events");
        if(events && objectp(events))
        {
            events->notify("onAdvancedRank");
        }

        persistChanges();
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int demoteRank(string guild)
{
    int ret = 0;
    if(memberOfGuild(guild))
    {
        guilds[guild]["rank"] = guildsDictionary()->demoteRank(
            this_object(), guild, guilds[guild]["rank"]);

        guilds[guild]["title"] = guildsDictionary()->title(guild, 
            guilds[guild]["level"], guilds[guild]["rank"]);
        guilds[guild]["pretitle"] = guildsDictionary()->pretitle(guild, 
            guilds[guild]["level"], guilds[guild]["rank"]);

        object materialAttributes = getService("materialAttributes");
        if(materialAttributes && objectp(materialAttributes))
        {
            guilds[guild]["rank advanced at"] = materialAttributes->Age();
        }

        object events = getService("events");
        if(events && objectp(events))
        {
            events->notify("onDemotedRank");
        }

        persistChanges();
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int joinGuild(string guild)
{
    int ret = 0;
    if(!memberOfGuild(guild) && member(guilds, guild) && 
        mappingp(guilds[guild]) && member(guilds[guild], "left guild"))
    {
        // Former member wishing to re-join the guild. Some guilds may 
        // permanently ban old members, others have time limits, etc.
        ret = guildsDictionary()->canReJoinGuild(this_object(), guild, 
            guilds[guild]["left guild"]);
        if(ret)
        {
            m_delete(guilds[guild], "left guild");
            guilds[guild]["rank"] = guildsDictionary()->startingRank(guild);
            
            // During this "probationary period", you cannot advance in rank.
            object materialAttributes = getService("materialAttributes");
            if(materialAttributes && objectp(materialAttributes))
            {
                guilds[guild]["anathema"] = materialAttributes->Age() + 86400;
                guilds[guild]["rank advanced at"] = materialAttributes->Age();
            }            

            guilds[guild]["experience"] = 0;
            guilds[guild]["title"] = guildsDictionary()->title(guild, 
                guilds[guild]["level"], guilds[guild]["rank"]);
            guilds[guild]["pretitle"] = guildsDictionary()->pretitle(guild, 
                guilds[guild]["level"], guilds[guild]["rank"]);            
        }
    }    
    else if(!memberOfGuild(guild) && 
            guildsDictionary()->canJoinGuild(this_object(), guild))
    {
        ret = 1;
        guilds[guild] = ([
            "level": 0, // Yes, zero
            "experience": 0,
            "rank": guildsDictionary()->startingRank(guild),
            "title": guildsDictionary()->title(guild, 1, 
                guildsDictionary()->startingRank(guild)),
            "pretitle": guildsDictionary()->pretitle(guild, 1, 
                guildsDictionary()->startingRank(guild)),
        ]);

        object materialAttributes = getService("materialAttributes");
        if(materialAttributes && objectp(materialAttributes))
        {
            guilds[guild]["rank advanced at"] = materialAttributes->Age();
        }

        // This is done to set up all research / skill / ability points
        guilds[guild]["level"] = 
            guildsDictionary()->advanceLevel(this_object(), guild);  
    }
    if(ret)
    {
        // Trigger distribution of unassigned experience points
        addExperience(0);

        persistChanges();

        refreshCachedPartyDetails();

        object selector =
            clone_object("/lib/modules/guilds/advanceLevelSelector.c");
        selector->setGuild(guild);
        move_object(selector, this_object());
        selector->registerCompletionEvent(this_object(), "onJoinGuild");
        selector->registerEvent(
            load_object("/lib/modules/guilds/levelSelector.c"));
        selector->initiateSelector(this_object());
    }
    return ret;    
}

/////////////////////////////////////////////////////////////////////////////
public nomask int leaveGuild(string guild)
{
    int ret = 0;
    if(memberOfGuild(guild) && guildsDictionary()->canLeaveGuild(this_object(), guild))
    {
        ret = 1;
        object materialAttributes = getService("materialAttributes");
        if(materialAttributes && objectp(materialAttributes))
        {
            guilds[guild]["left guild"] = materialAttributes->Age();
            guilds[guild]["anathema"] = materialAttributes->Age() +
                guildsDictionary()->outcastUntilDelay(guild);
        }
    }

    if(ret)
    {
        object events = getService("events");
        if(events && objectp(events))
        {
            events->notify("onLeaveGuild");
        }

        persistChanges();
    }
    return ret;    
}

/////////////////////////////////////////////////////////////////////////////
public nomask int removeGuild(string guild)
{
    int ret = 0;

    if (memberOfGuild(guild) && guildsDictionary()->canLeaveGuild(this_object(), guild))
    {
        ret = 1;

        object research = getService("research");
        if (objectp(research))
        {
            research->removeResearchBySource(guild);
        }

        removeGuildData(guild);
        m_delete(guilds, guild);
    }

    if (ret)
    {
        object events = getService("events");
        if (events && objectp(events))
        {
            events->notify("onLeaveGuild");
        }

        persistChanges();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *guildsExtraAttacks()
{
    mapping *extraAttacks = ({ });
    foreach(string guild in m_indices(guilds))
    {
        if (memberOfGuild(guild) || (member(guilds, guild) &&
            member(guilds[guild], "left guild")))
        {
            extraAttacks += guildsDictionary()->extraAttacks(guild, 
                guilds[guild]["level"], guilds[guild]["rank"]);
        }
    }
    return extraAttacks + ({ });
}

/////////////////////////////////////////////////////////////////////////////
public nomask int guildsBonusTo(string bonus)
{
    int ret = 0;
    
    if(function_exists(bonus, guildsDictionary()))
    {
        foreach(string guild in m_indices(guilds))
        {
            if(memberOfGuild(guild) || (member(guilds, guild) &&
                member(guilds[guild], "left guild")))
            {
                ret += call_other(guildsDictionary(), bonus, guild,
                    guilds[guild]["level"], guilds[guild]["rank"]);
            }
        }
    }
    else if(function_exists("BonusSkillModifier", guildsDictionary()))
    {
        foreach(string guild in m_indices(guilds))
        {
            if (memberOfGuild(guild) || (member(guilds, guild) &&
                member(guilds[guild], "left guild")))
            {
                ret += call_other(guildsDictionary(), "BonusSkillModifier", 
                    guild, bonus, guilds[guild]["level"], 
                    guilds[guild]["rank"]);
            }
        }
    }
    return ret;
} 

/////////////////////////////////////////////////////////////////////////////
public nomask int costToAdvanceSkill(string skillType)
{
    int ret = 2;

    foreach(string guild in memberOfGuilds())
    {
        // Not redundant - also checks proper format/structure of guild mapping
        if(memberOfGuild(guild))
        {
            int costToAdvanceForGuild = 
                guildsDictionary()->costToAdvanceSkillOfType(guild, skillType);
            
            ret = (ret > costToAdvanceForGuild) ? costToAdvanceForGuild : ret;
        }
    }    
    return ret;
}    

/////////////////////////////////////////////////////////////////////////////
private nomask string experienceBar(string guild, string charset,
    string colorConfiguration, object configuration)
{
    string ret = "";
    int current = guildExperience(guild);
    int needed = guildsDictionary()->experienceToNextLevel(guild, guildLevel(guild));

    if (current >= needed)
    {
        ret = configuration->decorate(" Level up ", "level up", "score",
            colorConfiguration);
    }
    else
    {
        string bar = "==========";
        string emptyBar = "";

        if (charset != "screen reader")
        {
            bar[(10 * current) / needed..] = "";
            for (int i = ((10 * current) / needed); i < 10; i++)
            {
                emptyBar += ".";
            }

            if (charset == "unicode")
            {
                bar = regreplace(bar, "=", "\u25ac", 1);
                emptyBar = regreplace(emptyBar, "[.]", "\u2237", 1);
            }
        }
        else
        {
            bar = sprintf("   %3d%%   ", to_int(100 * (1.0 * current / needed)));
        }

        ret = configuration->decorate(sprintf("%s", bar),
                "bar", "score", colorConfiguration) +
            configuration->decorate(sprintf("%s", emptyBar),
                "empty bar", "score", colorConfiguration);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string guildsDetails()
{
    string colorConfiguration = "none";
    string charset = "ascii";
    object settings = getService("settings");
    if (objectp(settings))
    {
        colorConfiguration = settings->colorConfiguration();
        charset = settings->charsetConfiguration();
    }

    object configuration = getDictionary("configuration");
    object commandDictionary = getDictionary("commands");

    string ret = commandDictionary->banneredContent(colorConfiguration, charset,
        configuration->decorate(sprintf("%-75s",
            "Currently not a member of any guilds."), "information", "score",
            colorConfiguration));

    string *guildList = memberOfGuilds();

    if (sizeof(guildList))
    {
        ret = "";
        foreach(string guild in guildList)
        {
            string guildInfo = "";
            if (guild == "background")
            {
                guildInfo = configuration->decorate(sprintf("%-35s", 
                    "Developing your background story"), "information", 
                    "score", colorConfiguration);
            }
            else
            {
                guildInfo =
                    configuration->decorate("Guild: ", "content", "score",
                        colorConfiguration) +
                    configuration->decorate(sprintf("%-27s ", capitalize(guild) +
                    (guildRankName(guild) ? " (" +
                        capitalize(guildRankName(guild)) + ")" : "")),
                        "information", "score", colorConfiguration);
            }

            ret += commandDictionary->banneredContent(colorConfiguration, 
                charset, guildInfo +
                configuration->decorate("Level: ", "content", "score",
                    colorConfiguration) +
                configuration->decorate(sprintf("%-10d ", guildLevel(guild)),
                    "information", "score", colorConfiguration) +
                configuration->decorate("Experience: ", "content", "score",
                    colorConfiguration) +
                experienceBar(guild, charset, colorConfiguration, configuration));
        }
    }
    return ret;
}
