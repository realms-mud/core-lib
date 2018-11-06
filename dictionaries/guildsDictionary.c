//*****************************************************************************
// Class: guildsDictionary
// File Name: guildsDictionary.c
//
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private string BaseGuild = "lib/modules/guilds/baseGuild.c";
private mapping guildList = ([]);
private mapping guildBonusCache = ([]);

/////////////////////////////////////////////////////////////////////////////
public nomask object guildObject(string guild)
{
    object ret = 0;

    if(guild && stringp(guild) && member(guildList, guild) &&
       (file_size(guildList[guild]) > 0))
    {
        ret = load_object(guildList[guild]);     
        if(member(inherit_list(ret), BaseGuild) < 0)
        {
            ret = 0;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidGuild(string guild)
{
    object guildObj = guildObject(guild);
    return (guildObj && objectp(guildObj) && 
        (guildObj->guildName() != "BaseGuild"));
}
   
/////////////////////////////////////////////////////////////////////////////
public nomask int registerGuild(string location)
{
    int ret = 0;

    if (location && stringp(location) && sizeof(location) &&
        (location[0] != '/'))
    {
        location = "/" + location;
    }

    if (file_size(location) > 0)
    {
        object guild = load_object(location);
        guild->SetupGuild();

        if (guild && objectp(guild) &&
            (member(inherit_list(guild), BaseGuild) > -1) &&
            (guild->guildName() != "BaseGuild") &&
            !member(guildList, guild->guildName()))
        {
            ret = 1;
            guildList[guild->guildName()] = location;
            guildBonusCache[guild->guildName()] = ([]);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *validGuilds()
{
    return m_indices(guildList) + ({ });
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidGuildSet(string *guilds)
{
    int ret = 0;
    if(guilds && pointerp(guilds))
    {
        string *listOfValidGuilds = validGuilds();
        ret = 1;
        foreach(string guild : guilds)
        {
            ret &&= (member(listOfValidGuilds, guild) > -1);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canAdvanceLevel(object guildMember, string guild)
{
    int ret = 0;
    object guildObj = guildObject(guild);
    if(guildObj && objectp(guildObj))
    {
        ret = guildObj->canAdvanceLevel(guildMember);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canAdvanceRank(object guildMember, string guild, string rank)
{
    int ret = 0;
    object guildObj = guildObject(guild);
    if(guildObj && objectp(guildObj))
    {
        ret = guildObj->canAdvanceRank(guildMember, rank);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int valueIsCached(string guild, string bonus, int level,
    string rank)
{
    return member(guildBonusCache, guild) &&
        member(guildBonusCache[guild], level) &&
        member(guildBonusCache[guild][level], rank) &&
        member(guildBonusCache[guild][level][rank], bonus);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void cacheValue(mixed value, string guild, string bonus,
    int level, string rank)
{
    if (!member(guildBonusCache, guild))
    {
        guildBonusCache[guild] = ([]);
    }
    if (!member(guildBonusCache[guild], level))
    {
        guildBonusCache[guild][level] = ([]);
    }
    if (!member(guildBonusCache[guild][level], rank))
    {
        guildBonusCache[guild][level][rank] = ([]);
    }
    guildBonusCache[guild][level][rank][bonus] = value;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int lookUpBonus(string guild, string bonus, int level,
    string rank)
{
    int ret = 0;
    
    if (valueIsCached(guild, bonus, level, rank))
    {
        ret = guildBonusCache[guild][level][rank][bonus];
    }
    else
    {
        object guildObj = guildObject(guild);
        if (guildObj && objectp(guildObj))
        {
            ret = guildObj->queryBonus(bonus, level, rank);
        }
        cacheValue(ret, guild, bonus, level, rank);
    }
    return ret;
}
    
/////////////////////////////////////////////////////////////////////////////
public nomask int MaxHitPoints(string guild, int level, string rank)
{
    return lookUpBonus(guild, "bonus hit points", level, rank);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int MaxSpellPoints(string guild, int level, string rank)
{
    return lookUpBonus(guild, "bonus spell points", level, rank);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int MaxStaminaPoints(string guild, int level, string rank)
{
    return lookUpBonus(guild, "bonus stamina points", level, rank);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DefendAttackBonus(string guild, int level, string rank)
{
    return lookUpBonus(guild, "bonus defend attack", level, rank);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int AttackBonus(string guild, int level, string rank)
{
    return lookUpBonus(guild, "bonus attack", level, rank);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DefenseBonus(string guild, int level, string rank)
{
    return lookUpBonus(guild, "bonus defense", level, rank);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DamageBonus(string guild, int level, string rank)
{
    return lookUpBonus(guild, "bonus damage", level, rank);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealHitPoints(string guild, int level, string rank)
{
    return lookUpBonus(guild, "bonus heal hit points", level, rank);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealSpellPoints(string guild, int level, string rank)
{
    return lookUpBonus(guild, "bonus heal spell points", level, rank);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealStamina(string guild, int level, string rank)
{
    return lookUpBonus(guild, "bonus heal stamina points", level, rank);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealHitPointsRate(string guild, int level, string rank)
{
    return lookUpBonus(guild, "bonus heal hit points rate", level, rank);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealSpellPointsRate(string guild, int level,
    string rank)
{
    return lookUpBonus(guild, "bonus heal spell points rate", level, rank);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealStaminaRate(string guild, int level, string rank)
{
    return lookUpBonus(guild, "bonus heal stamina rate", level, rank);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int RecoverSpellPoints(string guild, int level, string rank)
{
    return lookUpBonus(guild, "bonus recover spell points", level, rank);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int ReduceSpellPoints(string guild, int level, string rank)
{
    return lookUpBonus(guild, "bonus reduce spell points", level, rank);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int RecoverStaminaPoints(string guild, int level, string rank)
{
    return lookUpBonus(guild, "bonus recover stamina points", level, rank);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int ReduceStaminaPoints(string guild, int level, string rank)
{
    return lookUpBonus(guild, "bonus reduce stamina points", level, rank);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusSkillModifier(string guild, string skill, int level,
    string rank)
{
    return lookUpBonus(guild, sprintf("bonus %s", skill), level, rank);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *extraAttacks(string guild, int level, string rank)
{
    mapping *ret = 0;

    if (valueIsCached(guild, "extra attacks", level, rank))
    {
        ret = guildBonusCache[guild][level][rank]["extra attacks"];
    }
    else
    {
        object guildObj = guildObject(guild);
        if (guildObj && objectp(guildObj))
        {
            ret = guildObj->getExtraAttacks(level, rank);
            cacheValue(ret, guild, "extra attacks", level, rank);
        }
    }

    return ret + ({ });
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canUseEquipmentOfType(object actor, object equipment)
{
    int ret = 1;

    if(actor && objectp(actor) && function_exists("memberOfGuilds", actor))
    {
        int expresslyProhibitedItem = 0;
        string *guildList = actor->memberOfGuilds();

        if(sizeof(guildList))
        {
            ret = 0;
            foreach(string guild in guildList)
            {
                object guildObj = guildObject(guild);
                if(guildObj && objectp(guildObj))
                {
                    ret ||= guildObj->canUseEquipmentOfType(equipment);
                    expresslyProhibitedItem ||= 
                        guildObj->isProhibitedEquipment(equipment);
                }
            }
        }
        ret &&= !expresslyProhibitedItem;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string title(string guild, int level, string rank)
{
    string ret = 0;
 
    if (valueIsCached(guild, "title", level, rank))
    {
        ret = guildBonusCache[guild][level][rank]["title"];
    }
    else
    {
        object guildObj = guildObject(guild);
        if (guildObj && objectp(guildObj))
        {
            ret = guildObj->title(level, rank);
            cacheValue(ret, guild, "title", level, rank);
        }
    }

    return ret;
}           

/////////////////////////////////////////////////////////////////////////////
public nomask string rankName(string guild, string rank)
{
    string ret = 0;

    if (valueIsCached(guild, "rank name", 1, rank))
    {
        ret = guildBonusCache[guild][1][rank]["rank name"];
    }
    else
    {
        object guildObj = guildObject(guild);
        if (guildObj && objectp(guildObj))
        {
            ret = guildObj->rankName(rank);
            cacheValue(ret, guild, "rank name", 1, rank);
        }
    }

    return ret;
}    

/////////////////////////////////////////////////////////////////////////////
public nomask string pretitle(string guild, int level, string rank)
{
    string ret = 0;
    
    if (valueIsCached(guild, "pretitle", level, rank))
    {
        ret = guildBonusCache[guild][level][rank]["pretitle"];
    }
    else
    {
        object guildObj = guildObject(guild);
        if (guildObj && objectp(guildObj))
        {
            ret = guildObj->pretitle(level, rank);
            cacheValue(ret, guild, "pretitle", level, rank);
        }
    }
    return ret;
}    

/////////////////////////////////////////////////////////////////////////////
public nomask int experienceToNextLevel(string guild, int level)
{
    int ret = 0;

    if (valueIsCached(guild, "experience needed", level, "default"))
    {
        ret = guildBonusCache[guild][level]["default"]["experience needed"];
    }
    else
    {
        object guildObj = guildObject(guild);
        if (guildObj && objectp(guildObj))
        {
            ret = guildObj->experienceToNextLevel(level);
            cacheValue(ret, guild, "experience needed", level, "default");
        }
    }

    return ret;
}       

/////////////////////////////////////////////////////////////////////////////
public nomask int advanceLevel(object guildMember, string guild)
{
    int ret = 0;
    
    object guildObj = guildObject(guild);
    if(guildObj && objectp(guildObj))
    {
        ret = guildObj->advanceLevel(guildMember);
    }
    return ret;
}     

/////////////////////////////////////////////////////////////////////////////
public nomask string advanceRank(object guildMember, string guild,
    string currentRank)
{
    string ret = 0;
    
    object guildObj = guildObject(guild);
    if(guildObj && objectp(guildObj))
    {
        ret = guildObj->advanceRank(guildMember, currentRank);
    }
    return ret;
}           

/////////////////////////////////////////////////////////////////////////////
public nomask string demoteRank(object guildMember, string guild,
    string currentRank)
{
    string ret = 0;
    
    object guildObj = guildObject(guild);
    if(guildObj && objectp(guildObj))
    {
        ret = guildObj->demoteRank(guildMember, currentRank);
    }
    return ret;
}            

/////////////////////////////////////////////////////////////////////////////
public nomask int outcastUntilDelay(string guild)
{
    int ret = 0;
    
    object guildObj = guildObject(guild);
    if(guildObj && objectp(guildObj))
    {
        ret = guildObj->outcastUntilDelay();
    }
    return ret;
} 

/////////////////////////////////////////////////////////////////////////////
public nomask string startingRank(string guild)
{
    string ret = 0;
    
    object guildObj = guildObject(guild);
    if(guildObj && objectp(guildObj))
    {
        ret = guildObj->startingRank();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private int joiningGuildProhibited(string guildToCheck, string guildToJoin)
{
    int ret = 1;
    object guildObj = guildObject(guildToCheck);
    if(guildObj && objectp(guildObj))
    {
        ret = member(guildObj->prohibitedGuilds(), guildToJoin) > -1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canJoinGuild(object guildMember, string guild)
{
    int ret = 0;
    
    object guildObj = guildObject(guild);
    if(guildMember && objectp(guildMember) && guildObj && objectp(guildObj))
    {
        ret = 1;
        string *prohibitedList = guildObj->prohibitedGuilds();

        // We can't rely on guild masters not being sloppy...
        foreach(string memberInGuild in guildMember->memberOfGuilds())
        {
            ret &&= !joiningGuildProhibited(memberInGuild, guild) &&
                (member(prohibitedList, memberInGuild) < 0);
        }
        ret &&= guildObj->checkPrerequisites(guildMember);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canReJoinGuild(object guildMember, string guild, int ageWhenLeftGuild)
{
    int ret = 0;

    if (guildMember && objectp(guildMember) && function_exists("Age", guildMember))
    {
        ret = guildMember->Age() >= (ageWhenLeftGuild + outcastUntilDelay(guild)) &&
            canJoinGuild(guildMember, guild);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canLeaveGuild(object guildMember, string guild)
{
    int ret = 0;
    
    object guildObj = guildObject(guild);
    if(guildObj && objectp(guildObj))
    {
        ret = guildObj->canLeaveGuild(guildMember);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int costToAdvanceSkillOfType(string guild, string type)
{
    int ret = 0;
    
    object guildObj = guildObject(guild);
    if(guildObj && objectp(guildObj))
    {
        ret = guildObj->costToAdvanceSkillOfType(type);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isNonCombatGuild(string guild)
{
    int ret = 0;

    object guildObj = guildObject(guild);
    if (guildObj && objectp(guildObj))
    {
        ret = guildObj->isNonCombatGuild();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void resetCache()
{
    guildBonusCache = ([]);
}
