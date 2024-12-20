//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("halgaladh");
    Gender("male");
    description("Halgaladh Arthellyn is very tall (7'4\") and strong.He's "
        "not the type to pick up a bow and dance around the perimeter. "
        "He'd rather get into the mix with his sword. Only a few in the "
        "Aegis guard are better with a sword. In combat, Halgaladh is "
        "an expert soldier like the rest of the guard. While doing "
        "battle, he keeps some level of awareness about what the rest "
        "of the unit is doing and works well with others to coordinate "
        "attacks. He understands his role as a point man in melee. "
        "Outside of combat, Halgaladh is headstrong and needs a strong "
        "leader in order to be content with following. Otherwise, he "
        "tends to butt in and take control. If he sees a direction, he "
        "is most likely to push hard to make it happen. He's not "
        "ambitious but he does think that a leader should set a direction "
        "and make it happen.\n\nHalgaladh is an expert woodsman in spite "
        "of his large stature. He is most comfortable in the north just "
        "south of where the forests begin to thin because of the frigid "
        "temperatures and extremely long winters.\n\nHalgaladh is noble "
        "and fierce and strong and true and loyal - all the things "
        "associated with his fathers before him. He is big hearted. "
        "You'll see him carving figurines to give out to children when "
        "he passes through towns along the way.");

    Race("maegenstryd");
    SetUpPersonaOfLevel("swordsman", 3);
    addSkillPoints(8);
    advanceSkill("long sword", 8);

    addTrait("/lib/instances/traits/educational/educated.c");
    addTrait("/lib/instances/traits/background/human/eledhelean/noble/arthellyn.c");

    object equipment = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    equipment->set("craftsmanship", 70);
    equipment->set("material", "meteoric iron");
    move_object(equipment, this_object());
    this_object()->equip(equipment);

    object generator = load_object("/tutorial/characters/aegis-equipment.c");
    generator->CreateAegisEquipment(this_object());

    addConversation("/tutorial/characters/halgaladh/startingConversation.c");
}
