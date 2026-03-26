//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights
// reserved. See the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Shadow of Kharand");
    set("short", "A book titled 'The Shadow of Kharand'");
    set("title", "The Shadow of Kharand: Whispers of the Lost City");
    set("aliases", ({ "shadow of kharand", "mirost tale", "dark vale",
        "kharand chronicles", "book" }));
    set("long", "An epic recounting of the rise of Kharand and the "
        "fall of the lands between the mountains and the Lonis River. "
        "Told in a narrative style, it blends the deeds of kings, "
        "the terror of the undead, and the courage of men and dwarves "
        "who witnessed horrors in the empty city of Mirost. "
        "Each chapter offers detailed accounts of exploration, "
        "preparation, and the ominous shadow growing over the region.");

    addChapter("Chapter 1: Whispers from Mirost",
        "The wind from the north carried a scent of iron and ash.\n"
        "Scouts returned to Hillgarath with tales of silent hills.\n"
        "Mirost, once a city of dwarves and men, lay empty.\n"
        "Its streets were choked with ruins, its gates unbroken.\n"
        "Rumors told of the dead walking in the mountain passes.\n"
        "No birds sang there; even the crows seemed afraid.\n"
        "Emendacil frowned as the envoys bowed before him.\n"
        "Reports are grim, sire, said one, voice low and tight.\n"
        "Some claim shadows move where no shadow should be.\n"
        "Areladur, his cousin, shifted uneasily beside the throne.\n"
        "He had journeyed through the Vale and seen many horrors.\n"
        "But this stillness was like a wound in the land.\n"
        "Messengers spoke of orcs fleeing the hills to the south.\n"
        "Their columns darkened forests, and villages trembled.\n"
        "Farmers spoke of cattle found dead with eyes wide open.\n"
        "Children whispered of shapes that slid between the trees.\n"
        "The council debated, voices rising and clashing like swords.\n"
        "Some counseled caution, sending spies into the mountain.\n"
        "Others urged preparation, mustering forces for what may come.\n"
        "Emendacil stood, and silence fell over the chamber like snow.\n"
        "He spoke slowly, Hillgarath will not be taken unawares.");

    addChapter("Chapter 2: Into the Silent Halls",
        "Areladur led a party through Mirost's empty streets.\n"
        "Cracked stone and shattered windows whispered of sudden flight.\n"
        "The air smelled of smoke and long-dead fires.\n"
        "Every echo of their boots made the walls seem alive.\n"
        "They found banners torn and scattered, symbols of ancient guilds.\n"
        "In the market square, wagons lay abandoned, their wheels splintered.\n"
        "Carts of grain rotted in the sun, unclaimed.\n"
        "Some among the men muttered prayers under their breath.\n"
        "Dwarves inspected the gates, murmuring of old wards broken.\n"
        "A tunnel beneath the keep led to darkness that did not recede.\n"
        "Shadows twisted as if aware of intruders, yet no wind stirred.\n"
        "One dwarf swore he saw movement in the corner of his eye.\n"
        "He called to the others, but only silence answered.\n"
        "Areladur drew his sword, edge singing in the still air.\n"
        "Every passage held a memory of violence, and perhaps more.\n"
        "Whispers rose like smoke: words in tongues long forgotten.\n"
        "The party camped inside the ruined hall, keeping watch.\n"
        "Sleep was fitful, haunted by cries that came from nowhere.\n"
        "When morning came, the city seemed smaller, the shadows longer.\n"
        "No one spoke of courage; only survival was counted.");

    addChapter("Chapter 3: The Rising Darkness",
        "News from scouts returned to Hillgarath in bits and fragments.\n"
        "Orc bands were gathering in the northern passes.\n"
        "Reports of creatures, neither living nor dead, sent shivers through men.\n"
        "Eledhel sent envoys to confer with Emendacil and Areladur.\n"
        "The alliance formed anew, albeit with fear and suspicion.\n"
        "Caravans carrying supplies to the border vanished without trace.\n"
        "Villagers fled, leaving homesteads to the shadows.\n"
        "Some brought tales of the dead walking in the night.\n"
        "Others swore of a terrible figure in black atop Utumnadh.\n"
        "The mountains seemed alive with malignant intent.\n"
        "Areladur called the dwarves of Khazurath to council.\n"
        "They spoke of ancient magic stirring in Mirost's ruins.\n"
        "Weapons were reforged, armor polished, and spells whispered anew.\n"
        "Banners were hoisted to rally men and dwarves alike.\n"
        "Yet even the bravest felt dread that could not be named.\n"
        "Councils debated sending a strike, but the terrain favored shadows.\n"
        "Every strategy seemed to fail before it could be tried.\n"
        "Whispers spread: the darkness in Mirost was more than orcs.\n"
        "Some believed a fallen power lingered, hungering for life.\n"
        "And so, the allies prepared, hearts heavy with foreboding.");

    addChapter("Chapter 4: The March to Kharand's Shadow",
        "The armies of Hillgarath and Eledhel moved northward.\n"
        "Snow fell lightly, dusting the dead streets of Mirost.\n"
        "Every step seemed to echo with ghosts of the city's past.\n"
        "Dwarves grumbled at the cold, at the silence, and at the fear.\n"
        "Areladur rode at the front, eyes scanning the horizon.\n"
        "Scouts returned with tidings of orcish patrols growing bolder.\n"
        "The dead were reported seen, yet none could be touched.\n"
        "Banners snapped in the wind as if trying to warn the living.\n"
        "Camps were set with watchfires and wards of protection.\n"
        "Nights were restless; men muttered in their sleep of shadow figures.\n"
        "Areladur kept a journal of every event, every unnatural sight.\n"
        "He wrote of fear, of courage, and of hope tinged with despair.\n"
        "Some knights swore to honor fallen comrades long dead.\n"
        "The mountains above seemed to breathe, cold and menacing.\n"
        "Every dawn brought news of Kharand's advancing influence.\n"
        "Yet the alliance pressed on, for to retreat was to surrender hope.\n"
        "The journey would last months, each day heavier than the last.\n"
        "Whispers of the dark power grew, carried on the winds.\n"
        "Still, the men and dwarves of the Vale marched, unyielding.\n"
        "The stage was set for confrontation, in shadows and snow.");
}
