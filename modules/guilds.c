//*****************************************************************************
// Class: guilds
// File Name: guilds.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/organizations.c";
#include "/lib/modules/secure/guilds.h"

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
public nomask int effectiveLevel()
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
            ret += guilds[guild]["level"];
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int memberOfGuild(string guild)
{
    return(guild && stringp(guild) && member(guilds, guild) && 
           mappingp(guilds[guild]) && member(guilds[guild], "level") &&
           member(guilds[guild], "experience") && 
           member(guilds[guild], "rank") &&
           !member(guilds[guild], "left guild"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *memberOfGuilds()
{
    string *ret = ({ });
    if(sizeof(guilds))
    {
        ret = filter(m_indices(guilds), #'memberOfGuild);
    }
    return ret + ({ });
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
    int ret = 0;

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
    int ret = 0;
    if (memberOfGuild(guild) && intp(guilds[guild]["experience"]))
    {
        ret = guildsDictionary()->experienceToNextLevel(guild, guildLevel(guild)) -
            guilds[guild]["experience"];
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
public nomask int addExperience(int amount)
{
    int ret = 0;
    if (sizeof(guilds))
    {
        amount += unassignedExperience;
        unassignedExperience = 0;
        float guildLevels = to_float(effectiveLevel());
        foreach(string guild in memberOfGuilds())
        {
            // Since to_int truncates, the 0.5 is added to handle rounding issues.
            guilds[guild]["experience"] += to_int(0.5 + amount * 
                (guildLevel(guild) / guildLevels));

            int maxExp = 2 * guildsDictionary()->experienceToNextLevel(guild, guildLevel(guild));
            if(guilds[guild]["experience"] > maxExp)
            {
                guilds[guild]["experience"] = maxExp;
            }
        }
        ret = amount;
    }
    else
    {
        unassignedExperience += amount;
        ret = unassignedExperience;
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

        object events = getService("events");
        if(events && objectp(events))
        {
            events->notify("onAdvancedLevel");
        }
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

        object events = getService("events");
        if(events && objectp(events))
        {
            events->notify("onJoinGuild");
        }
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
private nomask string experienceBar(string guild)
{
    string format = "[0;34;1m%s[0m";
    int current = guildExperience(guild);
    int needed = guildsDictionary()->experienceToNextLevel(guild, guildLevel(guild));

    string bar = "==========";
    if (current >= needed)
    {
        bar = "[0m[0;33;1m Level up ";
    }
    else
    {
        bar[(10 * current) / needed..] = "[0m[0;31m";
        for (int i = ((10 * current) / needed); i < 10; i++)
        {
            bar += ".";
        }
    }
    return sprintf(format, bar);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string guildsDetails()
{
    string format = "[0;31m|[0m [0;36mGuild:[0m [0;33m%-27s[0m [0;36mLevel:[0m [0;33m%-10s[0m [0;36mExperience:[0m [0;33m%-11s[0m [0;31m|[0m\n";
    string ret = sprintf("[0;31m|[0m [0;33m%-75s[0m [0;31m|[0m\n",
        "Currently not a member of any guilds.");

    string *guildList = memberOfGuilds();

    if (sizeof(guildList))
    {
        ret = "";
        foreach(string guild in guildList)
        {
            ret += sprintf(format, capitalize(guild) +
                (guildRankName(guild) ? " (" + 
                    capitalize(guildRankName(guild)) + ")" : ""),
                to_string(guildLevel(guild)),
                experienceBar(guild));
        }
    }
    return ret;
}