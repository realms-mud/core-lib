//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "A Soldier Among the Sickness");
    set("short", "A Diary about the plague");
    set("title", "A Soldier Among the Sickness: Witness to Plague");
    set("aliases",
        ({ "plague diary", "soldier plague account", "sickness saga",
            "book", "diary" }));
    set("long",
        "A soldier recounts the days and nights of the plague: the horror, "
        "the sorrow, the fear, and the rare glimpses of grim humor. "
        "The narrative follows no calendar, only memory and survival.");

    addChapter("The First Signs",
        "The wind smelled wrong, sharp and biting.\n"
        "We saw bodies before we knew what had come.\n"
        "A mother clutched her child, eyes wide and empty.\n"
        "The cattle were down in the fields, twitching, silent.\n"
        "The town doctor shook his head; no words would follow.\n"
        "We burned the first hut, smoke choked our lungs, but it stank less\n"
        "than the inside. I laughed once at a man who tripped over his own\n"
        "fear. We knew the smell of death now, and it followed us like a\n"
        "shadow. Rivers swelled, not with rain, but with the bodies we\n"
        "could not bury. We were all alive, yet part of us had already\n"
        "joined them.\n");

    addChapter("The Long Days",
        "We moved among the sick, hands trembling, hearts hollow.\n"
        "Every cough made us flinch, every whisper was a prayer or a scream.\n"
        "I found myself counting rations instead of people.\n"
        "The children stared at us with blank faces; their parents gone.\n"
        "We joked sometimes, too bitterly, too darkly, and it saved no one.\n"
        "I saw a man pull his own fingers from a corpse to eat, and smiled\n"
        "faintly. It was not hunger but something else, a fracture in our\n"
        "minds. We washed hands until they cracked, but the plague seeped\n"
        "into the soul. No prayers reached the skies; the wind carried only\n"
        "the moans. I wrote letters I would never send, to people I could\n"
        "not remember.\n");

    addChapter("Night and Silence",
        "The nights were the worst; shadows moved with a mind of their own.\n"
        "We slept in barns with the rats, because bodies crowded our homes.\n"
        "I dreamt of mothers calling for children, children calling for mothers.\n"
        "A dog followed me one night; it left in the morning, lifeless.\n"
        "I laughed when I tripped over a grave marker in the dark.\n"
        "We shared our rations, though we knew sharing was madness.\n"
        "Our eyes were hollow, but still we marched among the living.\n"
        "We joked about the dead outranking us soon, and it felt true.\n"
        "The sky seemed lower, pressing on our shoulders, heavier than grief.\n"
        "I thought I had forgotten fear, but fear had simply forgotten me.\n");

    addChapter("The Edge of Humanity",
        "We began to see ourselves in the dead; every mirror reflected rot.\n"
        "We whispered to corpses, expecting answers, or at least comfort.\n"
        "I could no longer remember my own name without effort.\n"
        "Humor became survival; a laugh, a snarl, anything human.\n"
        "We stole bread from the dead, because the living were not generous.\n"
        "I held a child once, and it smelled of sickness and hope.\n"
        "We argued, fought, and prayed to nothing; it felt like devotion.\n"
        "Every day, a little more of the soldier inside me died.\n"
        "And yet, when the wind cleared, I saw the horizon and kept moving.\n"
        "We survived, not as men, but as fragments, shards of memory and shadow.\n");
}
