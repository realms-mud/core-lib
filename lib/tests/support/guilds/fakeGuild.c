//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public int testAddLevelPrerequisite(int level, mapping prerequisiteList)
{
    return baseGuild::addLevelPrerequisite(level, prerequisiteList);
}

/////////////////////////////////////////////////////////////////////////////
public int testAddRankPrerequisite(string rank, mapping prerequisiteList)
{
    return baseGuild::addRankPrerequisite(rank, prerequisiteList);
}

/////////////////////////////////////////////////////////////////////////////
public int testAddRank(string rank, mapping criteria)
{
    return baseGuild::addRank(rank, criteria);
}

/////////////////////////////////////////////////////////////////////////////
public int testSetDefaultRank(string rank)
{
    return baseGuild::setDefaultRank(rank);
}

/////////////////////////////////////////////////////////////////////////////
public int testAddPreferredSkillType(string type)
{
    return baseGuild::addPreferredSkillType(type);
}

/////////////////////////////////////////////////////////////////////////////
public int testAddCriteria(string key, mapping criteria)
{
    return baseGuild::addCriteria(key, criteria);
}

/////////////////////////////////////////////////////////////////////////////
public void testProhibitLeavingGuild()
{
    return baseGuild::prohibitLeavingGuild();
}

/////////////////////////////////////////////////////////////////////////////
public int testProhibitedGuildCombinations(string *guilds)
{
    return baseGuild::prohibitedGuildCombinations(guilds);
}

/////////////////////////////////////////////////////////////////////////////
public int testAddEquipmentProhibition(string type, string *data)
{
    return baseGuild::addEquipmentProhibition(type, data);
}
