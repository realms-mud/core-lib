//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Argloth: Descent into Zhardeg");
    set("short", "A journal about Argloth's Expedition, Vol II");
    set("title",
        "Argloth's Journals: The Shadow of Zhardeg");
    set("aliases",
        ({ "argloth journal", "journal", "book", "diary", "volume 2", "vol ii",
            "a journal about argloth's expedition, vol ii" 
            }));
    set("long",
        "A record of Argloth's expeditions to Zhardeg and the surrounding "
        "mountains. Each chapter is a fragment from his journal, showing "
        "how fascination with power slowly overcame prudence and duty.");

    addChapter("The Dragon Above",
        "Sylthasis stirs in the peak, a coil of shadow and heat.\n"
        "The men shiver, their axes trembling in the cold wind.\n"
        "I see the scales gleam even in moonlight, black as the mountain itself.\n"
        "I cannot look away; I feel a pull in my chest, a hunger I do not name.\n"
        "One dwarf whispers, 'Best we wait for dawn.'\n"
        "I shake my head. Dawn is a delay. Power does not wait.\n"
        "The dragon exhales fire into the night, and the smell of smoke bites my lungs.\n"
        "I feel it judging me, measuring my heart. I welcome the scrutiny.\n"
        "I shout, 'Come, wyrm! Show me what you are!' and my voice cracks.\n"
        "The men hesitate, fear written on every face.\n"
        "I press forward, torch raised, pulse racing, chest tight with thrill.\n"
        "Sylthasis descends, wings like black thunder, eyes like molten gold.\n"
        "I feel its mind brushing against mine, immense and patient.\n"
        "Yet I cannot turn away; the pull is intoxicating.\n"
        "I strike with spear and spell, each blow echoing in the mountains.\n"
        "The dwarves fight beside me, but I feel detached, watching my own hands.\n"
        "The dragon roars, a sound that shakes stone and bone alike.\n"
        "I taste blood, smoke, and fear; yet fear is a spice, not a barrier.\n"
        "This is the first true test; the first step toward power.\n"
        "[Marginal note: 'I understood then that fascination and fear were intertwined.']");

    addChapter("The Fissure Widens",
        "Sylthasis retreats into the upper cliffs, taunting with a hiss.\n"
        "I follow, heart hammering, dwarves straining to keep up.\n"
        "The mountain trembles under each beat of its wings.\n"
        "A boulder dislodges; I catch a dwarf mid-fall, his scream echoing.\n"
        "I feel a pang of guilt, quickly buried under exhilaration.\n"
        "The dragon circles, above, below, a living storm of shadow.\n"
        "I feel my thoughts unspooling, vision narrowing to a single point.\n"
        "The power I crave, the knowledge I seek, seems just within reach.\n"
        "I shout challenges, half to Sylthasis, half to myself.\n"
        "The dwarves mutter prayers; I ignore them, listening only to the pulse.\n"
        "I taste the first real thrill of defiance, of being more than a man.\n"
        "I do not hear the fear in my own voice until I write it later.\n"
        "The dragon dives, we clash, fire and steel mingling in a terrible ballet.\n"
        "I survive by instinct, luck, and a growing recklessness.\n"
        "The fissure opens wider in my mind; caution is gone.\n"
        "I feel something else awaken within me, a hunger beyond conquest.\n"
        "I will not retreat. I cannot retreat. To retreat is to die within.\n"
        "[Marginal note: 'Here I first glimpsed the shadow I would become.']");

    addChapter("Night of Smoke and Stone",
        "The mountain groans as Sylthasis lashes the cliffside.\n"
        "I smell fire and iron, see dwarves smashed into stone.\n"
        "I grab a torch and charge, ignoring screams that pierce my thoughts.\n"
        "The dragon's tail sweeps, throwing dust and men alike into the void.\n"
        "I feel hands on my shoulder - dwarf hands - steadying, urging retreat.\n"
        "I shake them off; retreat is a word from another life.\n"
        "I climb higher, breath burning, torch trembling, mind alight with obsession.\n"
        "Each step closer feels like defiance, yet also seduction.\n"
        "I glimpse runes etched in the cliffs, pulsing faintly in firelight.\n"
        "They hum to me; I feel them answering, awakening, tempting.\n"
        "I shout to the dragon, to the stones, to the mountain itself.\n"
        "The dwarves mutter warnings, prayers, curses; I hear none of it.\n"
        "Smoke fills my lungs, my eyes sting, but I press forward.\n"
        "I see Sylthasis' eyes, and I think I understand power for the first time.\n"
        "I strike again, the torch flaring, the mountain shaking with wrath.\n"
        "I am exhilarated, terrified, alive, unhinged.\n"
        "The fissure is full now; restraint is a memory.\n"
        "[Marginal note: 'Power whispered. I answered. I cannot unhear it.']");

    addChapter("The Whisper of Zhardeg",
        "I descend to the chamber beneath the cliffs, stones cold and alive.\n"
        "The dwarves hesitate, staring at walls that seem to breathe.\n"
        "I place my hand on the runes; they pulse in response.\n"
        "A voice whispers - not out loud, but inside my skull.\n"
        "'Power, Argloth. Take it. All of it.'\n"
        "I gasp, but my hand does not retreat; it sinks into the stone.\n"
        "The dwarves mutter warnings. I ignore them, fingers tingling.\n"
        "I feel the pulse of Zhardeg, the rhythm of mountains and dragon alike.\n"
        "The whispers grow insistent, coaxing, urging action.\n"
        "I write in my journal: 'I am no longer master here. I am participant.'\n"
        "The men glance at each other, fear in their eyes. They do not speak.\n"
        "I feel the first true spark of what they will later call corruption.\n"
        "Sylthasis' presence merges with the tower, with stone, with me.\n"
        "I know I must continue, though I sense a line I will soon cross.\n"
        "My pulse is the pulse of Zhardeg, my breath is the wind over Utumnadh.\n"
        "I shiver, but not from cold. Something inside me has awakened.\n"
        "[Marginal note: 'I cannot name it. It is hunger, it is knowledge, it is fear.']");
}
