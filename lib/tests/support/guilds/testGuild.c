//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("test");
    addPreferredSkillType("combat");
    addRank("neophyte", ([ "name":"neophyte", "title" : "the title of titliness", "pretitle" : "Neophyte", "next rank" : "acolyte" ]));
    addRank("acolyte", (["name":"acolyte", "title" : "the title of titliness", "pretitle" : "Acolyte", "previous rank" : "neophyte", "next rank": "blargyte", "delay for next promotion" : 1]));
    addRank("blargyte", (["name":"blargyte", "title" : "the title of titliness", "pretitle" : "Blargyte"]));
    setDefaultRank("neophyte");
    addCriteria("hit points", ([
        "type": "modifier",
        "apply": "5 every level",
        "begin at level": 1,
        "end at level": 10
    ]));
    addCriteria("spell points", ([
        "type": "modifier",
        "apply": "at level 5"
    ]));
    addCriteria("weapon attack", ([
        "type": "attack",
        "apply": "1 every 10 levels"
    ]));
    addCriteria("attribute points", ([
        "type": "attribute points",
        "apply": "1 every 2 levels",
        "begin at level" : 2,
    ]));
    addCriteria("skill points", ([
        "type":"skill points",
        "apply": "5 every level"
    ]));
    addCriteria("research points", ([
        "type":"research points",
        "apply": "1 every level"
    ]));
    addCriteria("test tree", ([
        "type":"research tree",
        "apply": "at level 5",
        "research tree": "/lib/tests/support/guilds/testGuildResearchTree.c"
    ]));
    addCriteria("test research", ([
        "type":"research",
        "apply": "at level 2",
        "research object": "/lib/tests/support/research/testGrantedResearchItem.c"
    ]));
    addCriteria("long sword", ([
        "type":"skill",
        "apply": "1 every 2 levels"
    ]));

    addCriteria("acolyte research", ([
        "type":"research",
        "apply": "at rank acolyte",
        "research object": "/lib/tests/support/research/testGrantedResearchItem.c"
    ]));

    addCriteria("research choice", ([
        "name": "Test name",
        "description" : "Test description",
        "apply" : "at level 6",
        "research objects" : ({ "/lib/tests/support/research/testLimitedActiveResearchItem.c",
            "/lib/tests/support/research/testGrantedResearchItem.c" })
    ]));
}

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
public void resetProhibitions()
{
    CanLeaveGuild = 1;
    ProhibitedGuilds = ({});
    prohibitedEquipment = ([]);
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
