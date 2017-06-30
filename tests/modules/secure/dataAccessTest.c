//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object DataAccess;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    DataAccess = clone_object("/lib/modules/secure/dataAccess.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(DataAccess);
}

/////////////////////////////////////////////////////////////////////////////
void PlayerTypeReturnsCorrectWizardValueFromDatabase()
{
    ExpectEq("owner", DataAccess->playerType("maeglin"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerTypeReturnsPlayerWhenNotWizard()
{
    ExpectEq("player", DataAccess->playerType("gorthaur"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerTypeReturnsPlayerWhenNotInDatabase()
{
    ExpectEq("player", DataAccess->playerType("fake player"));
}

/////////////////////////////////////////////////////////////////////////////
void GetPlayerDataReturnsDataFromDatabase()
{
    mapping expected = ([ 
        "age": 1,
        "availableAttributePoints": 0,
        "availableResearchPoints": 0,
        "availableSkillPoints": 0,
        "charisma": 10,
        "constitution": 10,
        "dexterity": 12,
        "drugged": 3,
        "gender": 1,
        "ghost": 0,
        "guilds": ([ 
            "fighter": ([ 
                "anathema": 2222,
                "experience": 0,
                "left guild": 1111,
                "level": 5,
                "pretitle": "",
                "rank": "",
                "rank advanced at": 0,
                "title": "",
            ]),
            "mage": ([ 
                "anathema": 0,
                "experience": 133,
                "left guild": 0,
                "level": 16,
                "pretitle": "Mage",
                "rank": "acolyte",
                "rank advanced at": 2333,
                "title": "the blah blah",
            ]),
        ]),
        "headache": 1,
        "hitPoints": 100,
        "intelligence": 10,
        "intoxicated": 5,
        "invisible": 0,
        "longDescription": "This is a long description",
        "maxHitPoints": 110,
        "maxSpellPoints": 130,
        "maxStaminaPoints": 150,
        "messageIn": "arrives",
        "messageOut": "leaves",
        "name": "gorthaur",
        "onKillList": 0,
        "openResearchTrees": ({ "/lib/tree1.c", "/lib/tree2.c" }),
        "playerId": 2,
        "quests": ([ 
            "lib/tests/support/quests/testQuestItem.c": ([ 
                "is active": 1,
                "is completed": 0,
                "name": "Hail to the king, baby!",
                "state": "serve the king",
                "states completed": "meet the king##met the king",
            ]),
        ]),
        "race": "elf",
        "research": ([ 
            "/lib/some/path.c": ([ 
                "cooldown": 0,
                "research complete": 1,
                "time spent learning": 1,
                "time to complete learning": 0,
                "when research began": 3,
                "when research complete": 4,
            ]),
        ]),
        "researchChoices": ([ 
            "Test": ([ 
                "1": ([
                    "choice": "Test",
                    "description": "This is choice #1",
                    "key": "/lib/somekey.c",
                    "name": "Choice #1",
                    "type": "research object",
                ]),
                "2": ([ 
                    "choice": "Test",
                    "description": "This is choice #2",
                    "key": "/lib/blah.c",
                    "name": "Choice #2",
                    "type": "research object",
                ]),
            ]),
        ]),
        "skills": ([ 
            "blacksmith": 5,
            "long sword": 10,
        ]),
        "soaked": 2,
        "shortDescription": "blah",
        "spellPoints": 120,
        "staminaPoints": 140,
        "strength": 10,
        "stuffed": 4,
        "temporaryTraits": "/lib/tests/support/traits/testTraitWithDuration.c",
        "timeToHealHP": 6,
        "timeToHealSP": 8,
        "timeToHealST": 10,
        "traits": ([ 
            "/lib/tests/support/traits/testTrait.c": ([ 
                "added": 5555,
                "name": "Sword Boy",
            ]),
            "/lib/tests/support/traits/testTraitWithDuration.c": ([ 
                "added": 6666,
                "end time": 6677,
                "expire message": "This is an expire message.",
                "name": "Temporary Jerk",
                "triggering research": "/lib/tests/support/research/testTimedResearchItem.c",
            ]),
        ]),
        "unassignedExperience": 0,
        "whenCreated": "1993-09-23 15:33:15",
        "wimpy": 70,
        "wisdom": 10,
    ]);
    ExpectEq(expected, DataAccess->getPlayerData("gorthaur"));
}