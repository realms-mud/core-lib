//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("thomas");
    Gender(1);
    Race("maegenstryd");
    SetUpPersonaOfLevel("swordsman", 3);
    addTrait("lib/modules/traits/educational/soldier.c");
    addTrait("lib/modules/traits/background/human/eledhelean/noble/aladain.c");

    object equipment = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    equipment->set("craftsmanship", 70);
    equipment->set("material", "meteoric iron");
    move_object(equipment, this_object());
    this_object()->equip(equipment);

    object generator = load_object("/lib/tutorial/characters/aegis-equipment.c");
    generator->CreateAegisEquipment(this_object());

    addConversation("/lib/tutorial/characters/thomas/startingConversation.c");
}
