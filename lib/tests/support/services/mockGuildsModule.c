//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing";

private int useGuilds = 0;
private string guild = "";
private int level = 0;
private int experience = 0;
private object guildObj = 0;
private string rank = "";

/////////////////////////////////////////////////////////////////////////////
public void ToggleMockGuilds()
{
    useGuilds = !useGuilds;
    this_object()->resetCaches();
}

/////////////////////////////////////////////////////////////////////////////
public void SetGuild(string newGuild)
{
    guild = newGuild;
}

/////////////////////////////////////////////////////////////////////////////
public void SetGuildObject(object guild)
{
    guildObj = guild;
}

/////////////////////////////////////////////////////////////////////////////
public void SetLevel(int newLevel)
{
    level = newLevel;
}

/////////////////////////////////////////////////////////////////////////////
public void SetRank(string newRank)
{
    rank = newRank;
}

/////////////////////////////////////////////////////////////////////////////
public void SetExperience(int exp)
{
    experience = exp;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int guildsBonusTo(string bonus)
{
    return useGuilds * 5;
}

/////////////////////////////////////////////////////////////////////////////
public string *validGuildModifiers()
{
    return ({ "bonus reduce spell points", "bonus recover spell points",
        "bonus reduce stamina points", "bonus recover stamina points" });
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *guildsExtraAttacks()
{
    return useGuilds ? ({ (["attack type":"weapon"]), (["attack type":"weapon"]) }) : ({});
}

/////////////////////////////////////////////////////////////////////////////
public nomask int guildLevel(string check)
{
    return (guild == check) ? level : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string guildRank(string check)
{
    return (guild == check) ? rank : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int guildExperience(string check)
{
    return (guild == check) ? experience : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int memberOfGuild(string check)
{
    return (guild == check) ? useGuilds : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isAnathema(string check)
{
    return (guild == check) ? useGuilds : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *guildsResearchTrees()
{
    string *ret = ({});
    if (useGuilds && !experience)
    {
        ret = ({ "/lib/tests/support/guilds/testGuildResearchTree.c" });
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int costToAdvanceSkill(string skillType)
{
    return guildObj ? guildObj->costToAdvanceSkillOfType(skillType) : 2;
}
