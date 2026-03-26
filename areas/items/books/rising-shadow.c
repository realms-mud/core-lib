//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights
// reserved. See the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Rising Shadow: Kharand and the Lonis Vale");
    set("short", "A book titled 'The Rising Shadow'");
    set("title", "The Rising Shadow: Kharand and the Lonis Vale");
    set("aliases", ({ "rising shadow", "lonis chronicle", "kharand wars",
        "book", "the rising shadow"}));
    set("long", "This work recounts the years of upheaval following the "
        "fall of Mirost, the rise of Kharand under Zarnedh, and the "
        "struggles of Hillgarath and Eledhel to preserve their realms. "
        "It blends formal record, personal witness, and speeches of leaders.");

    addChapter("Chapter 1: Rumors on the Wind",
        "The wind from the north brought news like smoke and ash.\n"
        "Scouts returned to Hillgarath, faces pale and voices hushed.\n"
        "Orc bands had fled the mountains, leaving silence in their wake.\n"
        "Yet the silence itself seemed wrong, too thick, too heavy.\n"
        "Villagers whispered of shapes in the hills, moving without sound.\n"
        "Children spoke of glowing eyes among the rocks and snow.\n"
        "Areladur gathered the council, his hands trembling despite his age.\n"
        "Some envoys claimed the dead were rising in the high passes.\n"
        "The room fell quiet at such tales, though skepticism lingered.\n"
        "Banners of Hillgarath snapped in the wind, defiant but nervous.\n"
        "Scouts returned with strange marks upon the snow, not footprints.\n"
        "The alliance was frayed, yet no one dared ignore these signs.\n"
        "Areladur spoke slowly, Every shadow has a source, he said.\n"
        "We march, but we march with eyes open, hearts wary.\n"
        "Preparations were made; armor polished, weapons reforged.\n"
        "Dwarves inspected every gate and wall for weaknesses.\n"
        "Even the youngest knights felt a chill in their bones.\n"
        "The night before departure, fires burned late in every hall.\n"
        "Men and dwarves whispered prayers, or curses, as they could.\n"
        "The mountains themselves seemed to watch, cold and unyielding.");

    addChapter("Chapter 2: Through Mirost's Shadow",
        "Areladur led the vanguard into Mirost's ruins, boots crunching snow.\n"
        "Cracked stone and fallen towers whispered of sudden flight.\n"
        "The air smelled of old fires, long dead but not forgotten.\n"
        "Dwarves moved with suspicion, eyes scanning for more than orcs.\n"
        "Every echo of their passage seemed alive, watching, waiting.\n"
        "Abandoned wagons and broken carts lay scattered in the square.\n"
        "Some of the men muttered prayers; others cursed under breath.\n"
        "Shadows clung to corners as if aware of their intrusion.\n"
        "One dwarf swore he saw a figure move, then vanish.\n"
        "Areladur tightened his grip on his sword, the edge catching light.\n"
        "Smoke from distant chimneys was absent; only silence reigned.\n"
        "They found old banners torn, symbols of guilds long fallen.\n"
        "The keep's gates had been left intact, but the halls were hollow.\n"
        "Whispers rose as if the city itself murmured in memory.\n"
        "Night fell, and the campfires seemed to struggle against the dark.\n"
        "Sleep was broken by sounds that had no source.\n"
        "When dawn came, Mirost felt smaller, the shadows longer.\n"
        "Areladur wrote it all in his journal, recording fear and wonder.\n"
        "No one spoke of heroism; only survival was counted.\n"
        "The city was theirs, yet no one felt victory in the cold ruins.");

    addChapter("Chapter 3: The Hordes of Kharand",
        "Scouts returned with tidings of Kharand’s armies on the move.\n"
        "Zarnedh the Great had united the lands, his banners black and red.\n"
        "Villages burned, and the survivors fled southward into the Vale.\n"
        "The alliance gathered quickly, for hesitation meant annihilation.\n"
        "Areladur convened dwarves and knights, voices low and urgent.\n"
        "Messages carried tales of orcish patrols growing bolder by night.\n"
        "Some claimed to see figures moving in the snow that were not men.\n"
        "The dead, they whispered, and worse things that followed the dead.\n"
        "Alliances were renewed with Linmir and Meledwath, but doubts lingered.\n"
        "Beren of Hillgarath and Areladur of Eledhel rode together, silent.\n"
        "Scouts returned with news that the passes were watched by spies.\n"
        "The armies must move fast, but caution was heavier than armor.\n"
        "Councils debated whether to strike Kharand directly or wait.\n"
        "Some suggested spies and subterfuge, others favored open battle.\n"
        "The snow fell thickly, and the roads became uncertain and perilous.\n"
        "Men shivered in their cloaks; dwarves cursed the cold and the silence.\n"
        "Every dawn brought new reports of Kharand’s reach extending.\n"
        "The alliance pressed forward, hearts heavy, eyes wider still.\n"
        "The shadow of war had fallen on the Vale, and none could hide.\n"
        "Hope clung tightly, but fear whispered of a darkness beyond war.");

    addChapter("Chapter 4: Fires in the North",
        "The alliance moved north, banners snapping in the wind.\n"
        "Snow lay thick, covering roads, hiding pitfalls and corpses.\n"
        "Scouts returned with tales of villages emptied overnight.\n"
        "Men spoke of glowing eyes and shapes that slithered through forests.\n"
        "Dwarves inspected the passes, wards and runes renewed and reinforced.\n"
        "Caravans carrying supplies vanished into the hills, never to return.\n"
        "The dead were rumored to follow every night, leaving footprints that faded.\n"
        "Areladur and Beren rode at the front, faces drawn and pale.\n"
        "Each campfire burned low, men whispered prayers they did not feel.\n"
        "Knights recited the oaths of old, but their voices trembled.\n"
        "The mountains above seemed alive with malignant intent.\n"
        "At night, the snow whispered like voices, carrying news of death.\n"
        "Children were hushed, villagers trembling as shadows fell across fields.\n"
        "The allies pressed on, wary of both Kharand and the unseen.\n"
        "Every hill held the memory of battle; every stream reflected fear.\n"
        "Dwarves grumbled at the roads, the cold, and the silence.\n"
        "Yet the march continued, slow and deliberate, for retreat meant despair.\n"
        "Whispers spread: unseen watchers lingered beyond the ridges.\n"
        "The alliance prepared, knowing the coming fight would be hard.\n"
        "The mountains themselves seemed to wait, patient and eternal.");

    addChapter("Chapter 5: The First Clash",
        "Skirmishes began in the passes, orcs striking at the vanguard.\n"
        "Men fell silently, some to arrows, some to strange creatures unseen.\n"
        "Areladur held his line, dwarves forming walls of iron and stone.\n"
        "The air reeked of smoke, blood, and something else, sour and heavy.\n"
        "Knights shouted oaths, the sound echoing across the cliffs.\n"
        "Some orcs carried banners black as midnight, symbols unknown.\n"
        "Scouts vanished into the snow, leaving only tracks that faded.\n"
        "The dead were rumored to rise, yet none dared confirm the tales.\n"
        "Areladur prayed silently for guidance, knowing prayer may not suffice.\n"
        "Beren rode beside him, sword ready, eyes scanning the shadows.\n"
        "Cries of men and dwarves echoed as skirmishes raged like fire.\n"
        "Some knights laughed at the madness, a grim sound of survival.\n"
        "Dwarves hacked with axes, each strike against flesh or shadow alike.\n"
        "A wind carried whispers, chilling the blood and bending resolve.\n"
        "At dusk, the field lay strewn with bodies, yet the enemy remained.\n"
        "The allies huddled in camps, tending wounds and haunted minds.\n"
        "No fires burned fully; smoke rose only to mingle with fear.\n"
        "Whispers spread: Kharand’s army hid greater horrors yet unseen.\n"
        "Even the bravest felt dread gnawing at their courage.\n"
        "And so, the night fell heavy, promising a darker dawn.");

    addChapter("Chapter 6: Marching on Kharand",
        "The alliance pressed forward, weary but unbroken.\n"
        "Villages passed were silent, empty, or scorched to black.\n"
        "The dead seemed ever near, tracks appearing then fading.\n"
        "Scouts reported Kharand’s banners flying atop distant ridges.\n"
        "Dwarves whispered of old magics stirring in the mountains.\n"
        "Knights and soldiers huddled together, sharing sparse food.\n"
        "Areladur rode with Beren, discussing plans in low voices.\n"
        "Maps were consulted; rivers and passes marked with care.\n"
        "The mountains themselves loomed, silent witnesses to all.\n"
        "Men shivered not from cold but from the weight of stories heard.\n"
        "They spoke of horrors, some true, some whispered in fear.\n"
        "The alliance moved slowly, keeping eyes open for ambush.\n"
        "Every shadow could conceal Kharand’s soldiers or something worse.\n"
        "Dwarves carved runes into rock, wards against spirits and dark magic.\n"
        "Fires burned low; men slept lightly, dreaming of dead comrades.\n"
        "Whispers rose, then died, as if the wind itself remembered pain.\n"
        "The road to Kharand stretched, endless and treacherous.\n"
        "Yet the allied banners did not falter, hope their only shield.\n"
        "The march continued, each day heavier than the last.\n"
        "And all knew that battle awaited at the end of the frozen path.");
}
