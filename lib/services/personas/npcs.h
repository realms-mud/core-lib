//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping npcBlueprints = ([
    "innkeeper":([
        "description": "An innkeeper is stout and welcoming, with ruddy cheeks and "
            "well-worn hands from years of hauling kegs and tending fires. "
            "Their apron is perpetually stained, and their voice carries "
            "easily across a crowded room. They keep a keen ear for gossip "
            "and a sharp eye on the coin purse.",
        "category": "npcs",
        "is humanoid": 1,
        "primary skills": ({ "no armor", "common", "persuasion",
            "perception", "listen", "spot" }),
        "secondary skills": ({ "dodge", "dagger", "brewing" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "keeper", "barkeep" }),
        "base hit points": 50,
        "base spell points": 10,
        "base stamina points": 30
    ]),
    "blacksmith":([
        "description": "A blacksmith is broad and muscular, with soot-streaked skin "
            "and arms scarred from countless sparks. Their leather apron is "
            "scorched and battered, and their hands grip a heavy hammer with "
            "practiced ease. The ring of steel on steel follows them like "
            "a heartbeat.",
        "category": "npcs",
        "is humanoid": 1,
        "primary skills": ({ "hard leather", "no armor", "hammer",
            "blacksmithing", "weapon smithing", "metal crafting",
            "perception" }),
        "secondary skills": ({ "parry", "dodge", "common", "spot",
            "listen" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "smith" }),
        "equipment": ([
            "weapons":({ "hammers" }),
            "armor": ({ "light-armor" }),
        ]),
        "base hit points": 80,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "priest":([
        "description": "A priest is calm and composed, dressed in simple but well-kept "
            "vestments. Their eyes are gentle yet searching, and their hands "
            "are folded in an attitude of perpetual contemplation. They "
            "speak softly but with an authority born of deep conviction.",
        "category": "npcs",
        "is humanoid": 1,
        "primary skills": ({ "no armor", "common", "reading",
            "spellcraft", "perception", "divine essence", "healing" }),
        "secondary skills": ({ "dodge", "staff", "listen", "spot",
            "theology", "persuasion" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "cleric", "father" }),
        "equipment": ([
            "armor/clothing": ({ "robes" }),
        ]),
        "base hit points": 50,
        "base spell points": 100,
        "base stamina points": 30
    ]),
    "grocer":([
        "description": "A grocer is lean and industrious, with calloused fingers and "
            "a shrewd, appraising gaze. Their clothes are practical and "
            "well-patched, and they move about their wares with brisk "
            "efficiency, always ready to haggle over a price or recommend "
            "a particularly fine cut of cheese.",
        "category": "npcs",
        "is humanoid": 1,
        "primary skills": ({ "no armor", "common", "persuasion",
            "perception", "listen", "spot" }),
        "secondary skills": ({ "dodge", "dagger" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "aliases": ({ "merchant", "shopkeeper" }),
        "base hit points": 40,
        "base spell points": 10,
        "base stamina points": 25
    ]),
]);
