//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("donald");
    Gender(1);
    description("Donald Belathon appears to be about 32 years old. He is "
        "6'8\" tall and around 280 lbs.\n\nDonald's physical form is "
        "beginning to show the signs of middle-age that often accompany "
        "a life as hard, and interesting, as his. His large, well-built "
        "frame is beginning to show a little bit of paunch, but is well "
        "maintained for a soldier. His once defiantly red hair, which "
        "bespoke of his northerner heritage, has faded a bit, and is "
        "now streaking with bits of gray. Donald's full, well trimmed "
        "beard frames a face leathered by too many days in the harsh sun, "
        "and too many nights sleeping under the stars.\n\nDonald comes "
        "from a minor noble family that has considerable holding in the "
        "northern providences, mostly in costal lands. His father and "
        "uncles are all merchants, and the family amassed a decent "
        "fortune using their merchant fleet, bringing Northlander "
        "goods (such as wool, furs, and mined precious stones) to the "
        "citadels in the south. Donald was raised in an environment of "
        "relative comfort in a very harsh land, and he spent much of "
        "his youth hunting and fishing with his older brothers and "
        "many, many cousins.\n\nDonald has long been a student of the "
        "battle rituals and forms of his Northerner forebearers, and "
        "prefers to fight with a very long sword.");

    Race("maegenstryd");
    SetUpPersonaOfLevel("swordsman", 3);
    addTrait("lib/instances/traits/educational/soldier.c");
    addTrait("lib/instances/traits/background/human/eledhelean/noble/belathon.c");

    object equipment = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    equipment->set("craftsmanship", 50);
    equipment->set("material", "steel");
    move_object(equipment, this_object());
    this_object()->equip(equipment);

    object generator = load_object("/tutorial/characters/aegis-equipment.c");
    generator->CreateAegisEquipment(this_object());

    addConversation("/tutorial/characters/donald/startingConversation.c");
}
