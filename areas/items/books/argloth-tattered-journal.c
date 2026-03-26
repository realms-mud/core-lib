//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Fragments of Madness: The Diary of Argloth");
    set("short", "A tattered journal, scrawled in a trembling hand");
    set("title", "Fragments of Madness: Argloth's Last Writings");
    set("aliases", ({ "argloth diary", "fragments of madness", "mad diary",
        "book", "tattered journal", "journal", "diary" }));
    set("long", "This diary is the shattered record of Argloth's descent into "
        "madness, written in the aftermath of his obsession with Sylthasis and "
        "the Keepers of Zhardeg. The pages record horrors, fragmented thoughts, "
        "and fleeting glimpses of a man lost to darkness and ambition.");

    addChapter("Fragments of Thought",
        "The dragon moves in the mountain; I feel its breath.\n"
        "It is no longer dead, no longer mine, yet obeys.\n"
        "I touch its scales. Cold. Hard. Yet warm with shadow.\n"
        "I hear whispers in the stones. They tell me secrets.\n"
        "The dwarves stare at me. They do not understand.\n"
        "I do not understand myself. Yet I know power.\n"
        "The dead follow. They groan, they stumble, they listen.\n"
        "I feed them commands, and they obey. I taste their fear.\n"
        "The mountain hums beneath my boots, alive with old things.\n"
        "I cannot sleep. Sleep is for the weak, for the forgotten.\n"
        "I draw maps of blood and ash, charting what must be done.\n"
        "My hand shakes, yet writes with precision and malice.\n"
        "I laugh sometimes, quietly, when a corpse bows before me.\n"
        "I am both king and servant, master and prisoner.\n"
        "Each day I forget myself a little more, yet remember all.\n"
        "Sylthasis whispers. Zhardeg whispers. I whisper back.\n"
        "The voices are my counsel, my council, my conscience.\n"
        "I am alone, yet not alone. I am many, yet only I remain.\n"
        "There is a path forward, though it is dark and crooked.\n"
        "I will not turn back. I cannot. I will not.");

    addChapter("Observations of the Living",
        "The Werric Knights march, unaware, distant, and slow.\n"
        "I watch from the shadows, their discipline repugnant to me.\n"
        "They honor courage. I honor survival, or whatever remains.\n"
        "I see them smile. I remember laughter. It is gone.\n"
        "I speak to the dead dwarves. They nod; they obey. They never smile.\n"
        "A bird lands nearby. I wonder if it sees the same things I do.\n"
        "I whisper its name. It flies. I am not surprised.\n"
        "I envy the living. Their ignorance is bliss, their hope fragile.\n"
        "I taste the air of the valleys below. Sweet with ignorance.\n"
        "I consider walking among them, invisible, unstoppable.\n"
        "I stop. The dead cannot forgive mistakes. I cannot forgive myself.\n"
        "I trace the wounds on Sylthasis' scales, counting each scratch.\n"
        "I catalog horrors, both mine and theirs, in meticulous detail.\n"
        "I feel joy. It is bitter, sharp, but joy nonetheless.\n"
        "I write it down. Perhaps someone will read this, some day.\n"
        "Perhaps the mountain itself will read. Perhaps I do not exist.\n"
        "I sharpen my sword. The dead do not need steel. I do.\n"
        "I hear the whispers again. They are louder now.\n"
        "I am ready, or as ready as madness allows.\n"
        "I will see what comes next, and I will endure it alone.");

    addChapter("Ruminations on Power",
        "I held life and death in my hands; the taste lingers.\n"
        "I feel strength, yet it feels wrong, a theft from the natural order.\n"
        "The dwarves recoil. Their eyes accuse me. I cannot answer.\n"
        "Sylthasis coils beside me, breathing shadows.\n"
        "The mountain groans, and I nod in agreement. We are allies.\n"
        "I imagine their fear as a song, a hymn to my own ascent.\n"
        "I do not dream. Dreams are for the uncorrupted.\n"
        "I chart the movements of stars, of men, of dead things.\n"
        "I speak to Zhardeg. It whispers back. I obey, yet question.\n"
        "The mountain is a mirror. I see myself multiply, fracture.\n"
        "I wonder if I am the sum of my deeds, or something darker.\n"
        "I scratch notes in the walls of the tower; a diary of shadows.\n"
        "I recall my first victory, the first thrill, the first whisper.\n"
        "I know now that thrill was only a shadow of what is to come.\n"
        "Power is intoxicating, solitude is punishing, fear is nourishing.\n"
        "I will endure. I will rise. I will command.\n"
        "I write for myself, the dead, the mountain, the whispers.\n"
        "All will read, all will remember, all will tremble.\n"
        "Even I tremble, though none may see.\n"
        "I am Argloth, and the world bends to my shadow.");
}
