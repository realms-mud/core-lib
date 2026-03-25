//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Diary of a Soldier of Dor-Temnost");
    set("short", "A Diary");
    set("title",
        "Diary of a Soldier of Dor-Temnost: Witnessing the Eastern Campaigns");
    set("aliases",
        ({ "soldier diary", "diary of dor-temnost", "eastern campaigns diary",
             "book", "diary" }));
    set("long",
        "A fragmentary and intimate account written by one who fought, "
        "saw, and endured the horrors of the Eastern Campaigns. "
        "It blends fear, fleeting humor, and the slow erosion of humanity.");

    addChapter("March into the Unknown",
        "We left at dawn, mud clinging to boots and armor.\n"
        "The roads stretched empty, the wind bitter and hollow.\n"
        "Horses stumbled. Men cursed softly, then fell silent.\n"
        "I thought of home, but it was gone, swallowed by this war.\n"
        "We passed villages blackened, roofs smoldering, smoke thick.\n"
        "A boy ran from the ruins. I wanted to lift him, but could not.\n"
        "Even the birds had fled, leaving silence broken only by orders.\n"
        "I laughed once at a comrade's sneeze, covered in soot.\n"
        "It was the first laugh in days, bitter and shallow.\n"
        "By night, we huddled in the mud, half asleep, half listening.\n"
        "We spoke little. Sleep was fragile. Dreams of fire came instead.\n"
        "Some men sang quietly, off-key, trying to ward off madness.\n"
        "I wondered if I would remember courage, or only fear.\n"
        "Every step east felt like walking deeper into the abyss.\n"
        "The officers discussed strategy as if we were not present.\n"
        "I realized I had become invisible to those who mattered most.\n"
        "And I did not care.\n");

    addChapter("The First Fight",
        "Smoke burned my eyes before I even saw the enemy.\n"
        "A friend fell beside me, his scream piercing the chaos.\n"
        "I remember tasting copper on my tongue, my hands shaking.\n"
        "I could not help him. Could not even speak.\n"
        "A man behind me tripped over the dead, swearing, then laughed.\n"
        "I understood the laughter, though it felt wrong.\n"
        "I fought, but slowly the act became mechanical, without thought.\n"
        "The enemy broke. We advanced. The ground was littered with bodies.\n"
        "I remember staring at a pile of heads, counting them by instinct.\n"
        "No pride, no victory. Only the grim habit of survival.\n"
        "At night, we burned villages for warmth, stealing food and water.\n"
        "I told myself it was necessary. Yet a piece of me recoiled.\n"
        "The captain cursed us for taking too long. We cursed him silently.\n"
        "I slept against a wall of corpses, waking to screams.\n"
        "The smell was in my clothes for days, refusing to leave.\n"
        "And somewhere inside, I felt myself fade.\n");

    addChapter("Mirost and the Siege",
        "The walls of Mirost rose like the jaws of some terrible beast.\n"
        "Arrows rained. Smoke choked the sun. Men fell like wheat.\n"
        "I carried the wounded when I could. Some begged to die.\n"
        "I prayed once, quietly, and laughed at the futility.\n"
        "Orders came screaming, then vanished. I moved by muscle memory.\n"
        "The enemy burned our trenches. We burned theirs. The night was endless.\n"
        "I watched a boy I knew shot trying to drink from a puddle.\n"
        "I did not weep. I could not. My hands were sticky with mud and blood.\n"
        "A comrade told a joke about the emperor’s moustache. We laughed.\n"
        "The laughter felt wrong, yet necessary. It kept the madness at bay.\n"
        "I saw my own reflection in the water: hollow, dirt-smeared eyes.\n"
        "I realized I no longer recognized the man I had been.\n"
        "Some nights I dream of home, of bread and clean water.\n"
        "Some nights I dream only of screaming, and waking to it.\n");

    addChapter("Flight and Memory",
        "The city fell. We fled into hills and forests, ragged and hungry.\n"
        "Men abandoned others. Some stole what little remained.\n"
        "I carried the wounded, then left them, then returned, then left again.\n"
        "I cursed myself, cursed the emperor, cursed fate.\n"
        "We scavenged. We argued. We laughed sometimes, though none should.\n"
        "The nights were cold, the sky empty. I felt the old world die.\n"
        "We spoke of Eledhel and its banners with both fear and hatred.\n"
        "Survival had stripped the finer parts of our souls.\n"
        "I remember the faces of the dead most vividly.\n"
        "I remember my own reflection. I do not recognize it.\n"
        "I write this to remember, not to boast.\n"
        "To tell those who come after: war is not grand, only endless.\n"
        "We laughed, we fought, we fled, and we remembered.\n"
        "And in the remembering, perhaps some part of us endured.\n");
}
