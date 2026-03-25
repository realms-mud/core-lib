//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "A Soldier on Utumnadh");
    set("short", "A book titled 'The Battle on the Mountain'");
    set("title", "A Soldier on Utumnadh: Witness to Orcs and Shadow");
    set("aliases",
        ({ "utumnadh battle", "soldier mountain account", "orcs and darkness", "book" }));
    set("long",
        "A soldier recounts the Battle of Utumnadh from the mountain slopes: "
        "the terror of orcs, the presence of a dark power, and the slow "
        "erosion of humanity amidst fire, stone, and shadow.");

    addChapter("The Mountain Awakes",
        "Mist clung to the jagged peaks as dawn broke over Utumnadh.\n"
        "Orc drums echoed through the ravines, a sound like stone cracking.\n"
        "Smoke and shadow crawled along the cliffs, unnatural and heavy.\n"
        "We scrambled over loose rock, weapons slick with cold sweat.\n"
        "The wind carried the stench of rot and iron from the enemy below.\n"
        "A dark presence pulsed from the summit, more felt than seen.\n"
        "Men whispered names of long-dead gods, hoping for mercy.\n"
        "I gripped my sword until my arms trembled, muscles screaming.\n"
        "From the peaks, a scream rolled down: orcs raining from above.\n"
        "The mountain itself seemed alive, intent on crushing us.\n");

    addChapter("The First Clash",
        "We met the orcs on narrow ledges, shields pressed, spears braced.\n"
        "Each swing of a blade sent a man tumbling down cliffs.\n"
        "The dark power moved like smoke, twisting orcish cries into terror.\n"
        "I saw men vanish into shadows that were not cast by stone.\n"
        "Horses balked at the edge; some were dragged into the abyss.\n"
        "The wind screamed in our ears, carrying the smell of burning flesh.\n"
        "Our captain roared, 'Hold the line! Let none pass this ridge!'\n"
        "I struck at an orc twice my size; it laughed, eyes red as blood.\n"
        "Every foot forward cost a friend; every pause threatened the mountain.\n"
        "We realized fear was more deadly than the orcs themselves.\n");

    addChapter("Shadow on the Summit",
        "Above us, the dark being watched, an impossible shape against sky.\n"
        "It moved without form, and yet the mountain trembled at each step.\n"
        "Orcs rallied, frenzied by its will, bodies burning with unnatural rage.\n"
        "Arrows shattered rock and bone alike; the air rang with cries.\n"
        "I felt hands of the dark upon me, pressing, pulling, twisting thoughts.\n"
        "A friend screamed, but it was swallowed by the howling wind.\n"
        "We hacked, we parried, we clung to ledges like rats, hearts hollow.\n"
        "The world narrowed to stone under feet, the enemy before, the void below.\n"
        "Every scream echoed twice: once in ears, once in soul.\n"
        "I learned to see the shadow before it moved, barely, just barely.\n");

    addChapter("The Edge of Chaos",
        "The field narrowed, a choke within the pass.\n"
        "I stumbled over bodies that still twitched, and kept moving.\n"
        "A trumpet sounded, and the enemy faltered; a surge, a killing wave.\n"
        "I lost count of friends, of foes, only knew the rhythm of death.\n"
        "Men screamed oaths, gods' names, curses, nothing mattered but survival.\n"
        "I smelled the burned flesh of countless others, carried on wind.\n"
        "A horse reared over the edge of the cliff, rider screaming as he fell.\n"
        "I wanted to scream for them all, but no sound came from me.\n"
        "In the chaos, I glimpsed commanders on hills, shouting plans or prayers.\n"
        "We were part of something larger, yet alone in our terror.\n");

    addChapter("Survival",
        "By midday, the mountain was strewn with bodies and shattered shields.\n"
        "Smoke and blood mingled; the stench of orc and man was the same.\n"
        "The dark power whispered to some, and they leapt from cliffs.\n"
        "We carried the wounded down narrow passes, step by trembling step.\n"
        "Men who had laughed in training now quivered in silent horror.\n"
        "I caught my reflection in a pool; a stranger stared back.\n"
        "Hands trembled on hilt; the sun burned red behind twisted peaks.\n"
        "We survived by inches, by luck, by sheer unwillingness to die.\n"
        "Every corner of Utumnadh held death, and we pressed through it.\n"
        "The summit remained, dark and waiting, unbowed, indifferent.\n");

    addChapter("After the Battle",
        "The orcs scattered or fell; the dark presence receded into shadow.\n"
        "We counted bodies we could not name, and did not try.\n"
        "The mountain held our screams in its cliffs, its stones soaked in blood.\n"
        "I touched the edge of the summit and shivered, knowing its watch had not ended.\n"
        "We descended, hollowed, broken, carrying what remained of the living.\n"
        "Some laughed quietly, some wept; all of us were changed.\n"
        "Rivers ran brown with stone dust and blood, a testament to our struggle.\n"
        "I slept that night on cold earth, dreaming of shadow and orcish cries.\n"
        "Utumnadh stood above us, silent and eternal, indifferent as the void.\n"
        "And I knew we had survived, not whole, but alive, haunted forever.\n"
        "When I slept, I would dream of fire, mountains, and screaming.\n");
}
