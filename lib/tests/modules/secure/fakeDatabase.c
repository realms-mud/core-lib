//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
public nomask mapping Gorthaur()
{
    return ([ 
        "age": 1,
        "availableAttributePoints": 1,
        "availableResearchPoints": 3,
        "availableSkillPoints": 2,
        "blocks": ([]),
        "busy": 0,
        "character set": "ascii",
        "charisma": 15,
        "color setting": "3-bit",
        "constitution": 14,
        "dexterity": 12,
        "drugged": 3,
        "earmuffs": 0,
        "factions": ([
            "/lib/tests/support/factions/goodGuys.c":([
                "disposition": "fearful",
                "reputation": -1034,
                "last interaction": 666,
                "last interaction reputation": -1044,
                "number of interactions": 32,
                "disposition time": 777
            ]),
            "/lib/tests/support/factions/badGuys.c":([
                "disposition": "admiring",
                "reputation": 1011,
                "last interaction": 9999,
                "last interaction reputation": 1044,
                "number of interactions": 188,
                "disposition time": 2
            ]),
        ]),
        "gender": 1,
        "ghost": 0,
        "guilds": ([ 
            "fake fighter": ([ 
                "anathema": 2222,
                "experience": 0,
                "left guild": 1111,
                "level": 5,
                "pretitle": "",
                "rank": "",
                "rank advanced at": 0,
                "title": "",
            ]),
            "fake mage": ([ 
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
        "intelligence": 11,
        "intoxicated": 5,
        "invisible": 0,
        "inventory": ([ 
        ]),
        "location": StartLocation(),
        "longDescription": "This is a long description",
        "magicalMessageIn": "blah",
        "magicalMessageOut": "de-blahs",
        "maxHitPoints": 110,
        "maxSpellPoints": 130,
        "maxStaminaPoints": 150,
        "memberOfFactions": ({ "/lib/tests/support/factions/badGuys.c" }),
        "messageClone": "does stuff",
        "messageHome": "blarg",
        "messageIn": "is now here",
        "messageOut": "leaves",
        "money": 12345,
        "name": "gorthaur",
        "userName": "gorthaur",
        "onKillList": 1,
        "openResearchTrees": ({ "/lib/tests/support/research/testSecondResearchTree.c" }),
        "page size": 20,
        "playerId": 2,
        "pretitle": "Weasel Lord",
        "quests": ([ 
            "lib/tests/support/quests/fakeQuestItem.c": ([ 
                "is active": 1,
                "is completed": 0,
                "name": "Hail to the king, baby!",
                "state": "serve the king",
                "states completed": "meet the king##met the king",
            ]),
        ]),
        "race": "elf",
        "research": ([ 
            "/lib/tests/support/research/testGrantedResearchItem.c": ([ 
                "cooldown": 0,
                "research complete": 1,
                "time spent learning": 1,
                "time to complete learning": 0,
                "when research began": 3,
                "when research complete": 4,
            ]),
            "/lib/tests/support/research/testSustainedResearchItem.c": ([ 
                "cooldown": 0,
                "research complete": 1,
                "time spent learning": 1,
                "time to complete learning": 0,
                "when research began": 3,
                "when research complete": 4,
                "sustained active": 1,
                "active count": 2,
                "active modifier object": "/lib/items/modifierObject#blarf"
            ]),
        ]),
        "researchChoices": ([ 
            "Test": ([ 
                "1": ([ 
                    "choice": "Test",
                    "description": "This is choice #1",
                    "key": "/lib/tests/support/research/testPersistedActiveTraitResearch.c",
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
        "shortDescription": "blah",
        "skills": ([ 
            "blacksmith": 5,
            "long sword": 10,
        ]),
        "soaked": 2,
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
        "unassignedExperience": 321,
        "wimpy": 70,
        "wisdom": 13 
    ]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void PrepDatabase()
{
    catch(validateTestDatabase());
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping GetWizardOfLevel(string level, string name,
    string *groups)
{
    return ([ 
        "age": 1,
        "availableAttributePoints": 1,
        "availableResearchPoints": 3,
        "availableSkillPoints": 2,
        "blocks": ([]),
        "busy": 0,
        "character set": "ascii",
        "charisma": 15,
        "color setting": "3-bit",
        "constitution": 14,
        "dexterity": 12,
        "drugged": 3,
        "earmuffs": 0,
        "factions": ([
            "/lib/tests/support/factions/goodGuys.c":([
                "disposition": "fearful",
                "reputation": -1034,
                "last interaction": 666,
                "last interaction reputation": -1044,
                "number of interactions": 32,
                "disposition time": 777
            ]),
            "/lib/tests/support/factions/badGuys.c":([
                "disposition": "admiring",
                "reputation": 1011,
                "last interaction": 9999,
                "last interaction reputation": 1044,
                "number of interactions": 188,
                "disposition time": 2
            ]),
        ]),
        "gender": 1,
        "ghost": 0,
        "guilds": ([ 
            "fake fighter": ([ 
                "anathema": 2222,
                "experience": 0,
                "left guild": 1111,
                "level": 5,
                "pretitle": "",
                "rank": "",
                "rank advanced at": 0,
                "title": "",
            ]),
            "fake mage": ([ 
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
        "intelligence": 11,
        "intoxicated": 5,
        "invisible": 0,
        "inventory": ([ 
        ]),
        "location": StartLocation(),
        "longDescription": "This is a long description",
        "magicalMessageIn": "blah",
        "magicalMessageOut": "de-blahs",
        "maxHitPoints": 110,
        "maxSpellPoints": 130,
        "maxStaminaPoints": 150,
        "memberOfFactions": ({ "/lib/tests/support/factions/badGuys.c" }),
        "messageClone": "does stuff",
        "messageHome": "blarg",
        "messageIn": "is now here",
        "messageOut": "leaves",
        "money": 12345,
        "name": (name ? name : "earl"),
        "userName": (name ? name : "earl"),
        "onKillList": 1,
        "openResearchTrees": ({ "/lib/tests/support/research/testSecondResearchTree.c" }),
        "page size": 20,
        "playerId": 3,
        "pretitle": "Weasel Lord",
        "quests": ([ 
            "lib/tests/support/quests/fakeQuestItem.c": ([ 
                "is active": 1,
                "is completed": 0,
                "name": "Hail to the king, baby!",
                "state": "serve the king",
                "states completed": "meet the king##met the king",
            ]),
        ]),
        "race": "elf",
        "research": ([ 
            "/lib/tests/support/research/testGrantedResearchItem.c": ([ 
                "cooldown": 0,
                "research complete": 1,
                "time spent learning": 1,
                "time to complete learning": 0,
                "when research began": 3,
                "when research complete": 4,
            ]),
            "/lib/tests/support/research/testSustainedResearchItem.c": ([ 
                "cooldown": 0,
                "research complete": 1,
                "time spent learning": 1,
                "time to complete learning": 0,
                "when research began": 3,
                "when research complete": 4,
                "sustained active": 1,
                "active count": 2,
                "active modifier object": "/lib/items/modifierObject#blarf"
            ]),
        ]),
        "researchChoices": ([ 
            "Test": ([ 
                "1": ([ 
                    "choice": "Test",
                    "description": "This is choice #1",
                    "key": "/lib/tests/support/research/testPersistedActiveTraitResearch.c",
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
        "shortDescription": "blah",
        "skills": ([ 
            "blacksmith": 5,
            "long sword": 10,
        ]),
        "soaked": 2,
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
        "unassignedExperience": 321,
        "wimpy": 70,
        "wisdom": 13,
        "wizard level": level
    ]);
}
