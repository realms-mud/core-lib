//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("berenar");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("swordsman", 3);

    addTrait("lib/instances/traits/educational/tactician.c");

    object equipment = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    equipment->set("craftsmanship", 70);
    equipment->set("material", "meteoric iron");
    move_object(equipment, this_object());
    this_object()->equip(equipment);

    object generator = load_object("/tutorial/characters/aegis-equipment.c");
    generator->CreateAegisEquipment(this_object());

    addConversation("/tutorial/characters/berenar/startingConversation.c");
}
