//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Argloth: Descent into Zhardeg");
    set("short", "A journal about Argloth's Expedition, Vol III");
    set("title",
        "Argloth's Journals: The Shadow of Zhardeg");
    set("aliases",
        ({ "argloth journal", "journal", "book", "diary", "volume 3", "vol iii",
            "a journal about argloth's expedition, vol iii" 
            }));
    set("long",
        "A record of Argloth's expeditions to Zhardeg and the surrounding "
        "mountains. Each chapter is a fragment from his journal, showing "
        "how fascination with power slowly overcame prudence and duty.");

    addChapter("The Army Falls",
        "The first dwarf screams, a sound that cleaves the night.\n"
        "I hear the clang of axes against claws, the roar of orcs.\n"
        "Smoke and fire choke the air; I taste ash and iron.\n"
        "My men die around me, one by one, and I feel each loss.\n"
        "Yet I do not stop. My hands are steady, my mind alight.\n"
        "A dwarf falls, rolling into a crater of shattered stone.\n"
        "I reach for him, find only empty air; he is gone.\n"
        "I curse, a sound harsh and hollow in the mountain wind.\n"
        "Sylthasis' shadow looms; even death does not hide it.\n"
        "I feel the pull, stronger than ever, urging me to seize power.\n"
        "Another orc charges; I strike and the body crumples.\n"
        "The mountain shakes, dust and debris raining down.\n"
        "I realize the army is broken, scattered, almost nothing remains.\n"
        "I taste despair and exhilaration together, a bitter draught.\n"
        "The fissure within me widens; I feel I am no longer wholly Argloth.\n"
        "I mutter words of power, words I barely understand.\n"
        "[Marginal note: 'Loss sharpens focus, dissolves doubt.']");

    addChapter("Raising the Fallen",
        "The corpses lie before me: dwarf, orc, and man alike.\n"
        "Sylthasis' body sprawls in blackened ruin, wings still twitching.\n"
        "I feel a surge, a dark pulse from the mountain beneath.\n"
        "Hands trembling, I lay them on the dragon's corpse.\n"
        "A shiver races up my spine; I hear whispers, low and insistent.\n"
        "'Bind them to you,' it says, 'Bind them and rise.'\n"
        "I raise my voice, speak words not taught in any school.\n"
        "Flesh stiffens; eyes open, lifeless and unseeing.\n"
        "I stagger back, heart hammering; they obey, yet it is unholy.\n"
        "The dwarves mutter warnings, curses, prayers; I ignore them.\n"
        "The army of the dead rises, groaning, a tide of shadow.\n"
        "I feel their strength mingle with mine, and something inside snaps.\n"
        "I taste the first real power I sought, but it is bitter and cold.\n"
        "I know this is no victory, yet I cannot stop.\n"
        "[Marginal note: 'Life, death, and the space between are mine to command.']");

    addChapter("The Mountain Watches",
        "The cliffs of Utumnadh groan under the weight of the dead.\n"
        "I walk among them, and they obey without question.\n"
        "The living flee; the dying obey; I stand in the eye of power.\n"
        "I feel Sylthasis' spirit, bound to my will, pulsing in my veins.\n"
        "The mountain whispers secrets I cannot fully comprehend.\n"
        "I am exhilarated, terrified, more alive and less than myself.\n"
        "Every step forward feels like trespass into something divine and damned.\n"
        "I glance at the Werric Knights, see courage wane and despair bloom.\n"
        "They are too late; I am beyond pleading, beyond morality.\n"
        "I hear a voice - mine? - whispering praise for deeds not yet done.\n"
        "The shadows of Sylthasis stretch across the cliffs, a living cloak.\n"
        "I feel the pull of Zhardeg, guiding, urging, whispering.\n"
        "I have touched the void and it has touched me back.\n"
        "[Marginal note: 'There is no turning. Only the mountain and I.']");

    addChapter("The Corruption Settles",
        "Hours pass or days; I cannot measure time in blood and shadow.\n"
        "The dwarves cower, some weep, some join the dead under compulsion.\n"
        "I walk among the raised, counting none as enemy, none as friend.\n"
        "The pulse of Sylthasis is in my chest, the whisper of Zhardeg in my ears.\n"
        "I taste the thrill of command, the terror of omnipotence.\n"
        "I feel my thoughts twist, my desires sharpen into a single obsession.\n"
        "I remember the first fight, the first thrill, the first whisper.\n"
        "All led here, to the brink where mortality and madness meet.\n"
        "I know the Werric Knights approach; I see them on the cliffs above.\n"
        "I laugh, a sound bitter and hollow, echoing against stone.\n"
        "Let them come. Let them fight. I am beyond fear, beyond death.\n"
        "The mountain holds me, the dragon bends to me, the dead serve me.\n"
        "[Marginal note: 'Power is not victory. Victory is not survival.']");
}
