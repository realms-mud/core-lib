//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("alberich");
    Gender(1);
    Race("human");
    SetUpPersonaOfLevel("knifeman", 3);
    addTrait("lib/instances/traits/racial/eledhelHuman.c");
    addTrait("lib/instances/traits/educational/hunter.c");

    object equipment = clone_object("/lib/instances/items/weapons/swords/short-sword.c");
    equipment->set("craftsmanship", 50);
    equipment->set("material", "steel");
    move_object(equipment, this_object());
    this_object()->equip(equipment);

    object generator = load_object("/tutorial/characters/aegis-equipment.c");
    generator->CreateAegisEquipment(this_object());

    addConversation("/tutorial/characters/alberich/startingConversation.c");
}
