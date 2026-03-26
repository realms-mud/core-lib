//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights
// reserved. See the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Vale Reclaimed");
    set("short", "A book titled 'The Vale Reclaimed'");
    set("title", "The Vale Reclaimed: Chronicles of the Northward March");
    set("aliases", ({ "vale reclaimed", "kharand aftermath", "northward march",
        "chronicles of the vale", "book", "the vale reclaimed" }));
    set("long", "The story of the lands after Kharand's shadow passed, "
        "as Hillgarath, Eledhel, and the scattered remnants of the Vale "
        "strive to reclaim their homes. Courage, intrigue, and the rising "
        "threat of a restless power beyond the mountains shape these "
        "pages. Each chapter tells of exploration, battles, and the "
        "alliances formed to protect what remains of the northern lands.");

    addChapter("Chapter 1: Echoes of the Fallen",
        "The snow had melted, leaving trails of mud and broken timber.\n"
        "Hillgarath's scouts returned from Mirost with reports of silence.\n"
        "Villages once burned were now ghostly ruins, doors hanging from\n"
        "hinges. Areladur walked among the remnants of the city,\n"
        "remembering those lost. The dwarves of Khazurath whispered of\n"
        "wards broken and treasures vanished. Crows circled above, dark\n"
        "against a pale sun, unafraid of men. Some soldiers spoke of shapes\n"
        "moving in the distance, out of step with wind or shadow. The\n"
        "alliance gathered their strength, repairing armor, and sharpening\n"
        "blades. Messengers rode swiftly to Eledhel, bringing word of\n"
        "Kharand's encroachment. Areladur convened his council, reminding\n"
        "all that the Vale must hold together. Beren and Areladur planned\n"
        "their route to secure supply lines and watch the passes. Fear\n"
        "lingered, but discipline and resolve held the men steady. The\n"
        "northern forests seemed to breathe, leaves rustling though the air\n"
        "was still. Knights and dwarves patrolled, ears straining for\n"
        "whispers of the dead. Some claimed to hear cries of Mirost's\n"
        "victims carried on the wind. Even the bravest felt the weight of\n"
        "unseen eyes upon them. The first step to reclaim the Vale had\n"
        "begun, heavy with loss and hope. Maps were drawn, scouts\n"
        "dispatched, and nightly prayers whispered. The ghosts of the past\n"
        "mingled with the living, yet the living would not yield. And so\n"
        "the Vale stirred, readying itself for what was to come.");

    addChapter("Chapter 2: The Northern Passes",
        "Through winding mountain roads, the allies pressed cautiously.\n"
        "Rockslides and narrow trails slowed their advance, yet vigilance\n"
        "never wavered. Dwarves set wards along the cliffs, singing old\n"
        "chants of protection. Orc patrols were sighted, few in number but\n"
        "fierce in presence. Areladur led skirmishes, each a test of\n"
        "coordination and courage. Scouts reported lights and fires where\n"
        "none should have been. The nights grew colder, winds sharp against\n"
        "exposed faces. Stories spread of shadowed figures appearing and\n"
        "disappearing in the mist. Villagers who dared return spoke of\n"
        "voices calling from the mountains. Areladur paused to consider\n"
        "whether Kharand's magic lingered here. The dwarves murmured of\n"
        "ancient ruins, places best left undisturbed. Beren met with Eledhel\n"
        "envoys to discuss strategy for the passes. Supplies were\n"
        "stockpiled, routes planned for both attack and retreat. Some\n"
        "knights grew restless, eager for confrontation; others wary. A\n"
        "council of war was held under a starlit sky, banners fluttering in\n"
        "cold wind. Stories of the dead walking haunted their sleep, yet\n"
        "they rested only briefly. Plans were made to clear the passes\n"
        "before Kharand could entrench. Each morning brought reports of\n"
        "small victories and losses alike. Every soldier knew that the\n"
        "coming trials would test both courage and wisdom. And so the\n"
        "northern march continued, relentless and wary of the shadows.");

    addChapter("Chapter 3: Fires on the Ridge",
        "Smoke rose from a ridge beyond the trees, black and twisting.\n"
        "Areladur spurred his horse forward, scouts flanking the column.\n"
        "Orcs had made camp, careless and confident in their numbers. The\n"
        "first volley of arrows fell, and chaos erupted among the enemy.\n"
        "Dwarves charged with axes, their war-cries echoing off stone\n"
        "cliffs. Knights pressed forward, swords flashing in the pale light.\n"
        "The clash was brutal, dust and blood mixing with winter mud. Orcs\n"
        "fell, but the dead seemed to rise again, a dreadful repetition.\n"
        "Areladur and Beren fought side by side, rallying the men. Flames\n"
        "consumed tents and banners, painting the ridge in orange and\n"
        "black. The air was thick with smoke, sweat, and the cries of both\n"
        "living and dead. Dwarves blocked the enemy's retreat, chanting\n"
        "old hymns of defiance. Some knights swore they saw figures among\n"
        "the fire that should not exist. The sun dipped low, shadows\n"
        "lengthening unnaturally across the field. Victory was claimed,\n"
        "yet unease remained; the dead had not yet been put to rest.\n"
        "Areladur ordered the ridge secured, but vigilance would continue\n"
        "through the night. The men and dwarves set camp amidst the charred\n"
        "remains, wary of what lingered. No words of triumph were spoken;\n"
        "only quiet prayers for the fallen. Even in victory, the Vale felt\n"
        "the shadow of forces unseen. And still, they pressed onward, for\n"
        "retreat was no longer an option.");

    addChapter("Chapter 4: The Valley Reclaimed",
        "After weeks of careful marching and skirmishes, the valley opened\n"
        "before them. Houses were rebuilt, crops replanted, yet the scars of\n"
        "war remained. Areladur walked the streets with villagers, offering\n"
        "both protection and counsel. Dwarves reinforced fortifications,\n"
        "erecting watchtowers and gates. Beren negotiated with returning\n"
        "lords, solidifying new alliances. Reports from scouts indicated\n"
        "that Kharand forces were retreating beyond the mountains. The\n"
        "shadow lifted slightly, though whispers of unseen threats\n"
        "persisted. Children played where ashes had once lain, laughter a\n"
        "fragile sound. Priests and scholars began to restore shrines,\n"
        "libraries, and archives. Areladur convened a council to discuss the\n"
        "long-term security of the Vale. Dwarves reminded the council of\n"
        "wards and protective spells from ages past. Knights patrolled in\n"
        "pairs, their vigilance unwavering, though weary. Trade routes\n"
        "reopened cautiously, caravans guarded by armed men. Areladur and\n"
        "Beren rode through villages, listening to stories of endurance and\n"
        "bravery. Farmers recounted nights of terror and the courage it took\n"
        "to survive. The alliance strengthened, knowing that unity had\n"
        "reclaimed more than just land. Every day, the Vale grew more\n"
        "alive, yet shadows always lingered at the edges. Hope returned,\n"
        "tempered by memory and the knowledge of what had been lost. The\n"
        "Vale was free, for now, but vigilance would be eternal. And so the\n"
        "chronicles ended, with the land slowly healing under the watch of\n"
        "its protectors.");
}
