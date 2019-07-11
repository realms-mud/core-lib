//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("galadhel");
    description("Galadhel Marannuminas is one of the youngest members of the Aegis Guard. "
        "She is just shy of six feet tall and athletic. She has piercing gray "
        "eyes and raven black hair.\n\nHer father, one Bregolas, is a "
        "well-known retired general of the Eledhel army who now serves as "
        "one of the King's advisors in military affairs. She had two "
        "brothers who served with distinction in the Phaedra over a decade "
        "ago but the elder was lost in an orc ambush and the younger was "
        "presumed killed shortly after.\n\nGaladhel began training for the "
        "Aegis as soon as her father permitted it and threw herself "
        "completely into the rigors of schooling. She showed uncanny "
        "aptitude with the bow and matters of stealth. She is known largely "
        "as a sniper, though few use that particular vocabulary aloud.\n\n"
        "Her family is a respected one, light on scandal and heavy on "
        "loyalty to the kingdom. While none recently have occupied the "
        "throne, they have always been close to it, acting often as "
        "Stewards. They have been consistently chosen as advisors and "
        "ambassadors throughout Eledhel's history.\n\nAmongst the ranks "
        "of the Aegis, not much is known of Galadhel's actual personality. "
        "She has always done her best to stay in the periphery although, "
        "when called upon, she certainly can speak her peace.");

    Gender(2);
    Race("maegenstryd");
    SetUpPersonaOfLevel("archer", 3);
    addTrait("lib/instances/traits/background/human/eledhelean/noble/marannuminas.c");
    addTrait("lib/instances/traits/educational/hunter.c");

    object equipment = clone_object("/lib/instances/items/weapons/bows/bow.c");
    equipment->set("craftsmanship", 50);
    equipment->set("material", "kingwood");
    move_object(equipment, this_object());
    this_object()->equip(equipment);

    object generator = load_object("/lib/tutorial/characters/aegis-equipment.c");
    generator->CreateAegisEquipment(this_object());

    addConversation("/lib/tutorial/characters/galadhel/startingConversation.c");
    addConversation("/lib/tutorial/characters/galadhel/brendanOeldhenConversation.c");
}
