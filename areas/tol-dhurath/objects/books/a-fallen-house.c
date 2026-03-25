//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Memoirs of a Fallen House");
    set("short", "A book titled 'Memoirs of a Fallen House'");
    set("title", "Memoirs of a Fallen House");
    set("aliases",
        ({ "dor-temnost survivor", "fallen house memoirs",
           "witness to collapse", "memoirs", "book" }));
    set("long",
        "A somber, personal account written by one of the few who "
        "lived through the fall of Dor-Temnost. This work blends "
        "memory, lament, and careful observation.");

    addChapter("In the Shadow of the Crown",
        "I was born beneath the banners of Dor-Temnost,\n"
        "my family sworn to service for generations.\n"
        "We knew pride and duty, yet also fear and hunger.\n"
        "When Elonoch III rose, whispers spoke of recklessness.\n"
        "He commanded lands vast, yet seemed blind to need.\n"
        "Taxes pressed the poor, and watchmen turned their eyes.\n"
        "I remember my father saying, 'Power is nothing\n"
        "without those who serve it willingly.'\n"
        "We thought it folly then, but only years later\n"
        "would we understand how grave the warning.\n");

    addChapter("The Eastern Threat",
        "Rumors of Bregandil and his forces reached the court.\n"
        "We laughed at first, thinking them young men eager.\n"
        "Yet reports grew dire: cities falling, towns abandoned.\n"
        "And still our leaders debated, slow to act.\n"
        "We saw Dor-Lonis burn and Carandur taken,\n"
        "and yet the court remained seated, unsure.\n"
        "I recall soldiers muttering among themselves:\n"
        "'Shall we fight for men who do not fight for us?'\n"
        "That question spread like disease in ranks.\n"
        "Even the bravest hesitated before unknown banners.\n");

    addChapter("The Siege of Tirnost",
        "Tirnost, our last stronghold, felt like a tomb.\n"
        "Smoke rose from outer walls, and cries filled the night.\n"
        "We held gates as best we could, but fear corroded resolve.\n"
        "The emperor raged atop his walls, yet none could aid us.\n"
        "Men fell to cold and hunger as much as to steel.\n"
        "I saw friends, brothers in service, turned pale with despair.\n"
        "Some fled in the night, others prayed quietly, unheard.\n"
        "I myself wondered what future could await a fallen realm.\n"
        "And yet duty bound me, though it tasted bitter.\n"
        "When the breach was made, the city fell in solemn silence.\n");

    addChapter("Flight and Exile",
        "We left behind all we had ever known: halls, lands, graves.\n"
        "Khendrus became refuge for those who survived.\n"
        "We were many, yet scattered, each carrying stories of ruin.\n"
        "The emperor lingered, clinging to vestiges of power.\n"
        "We, the ordinary and the faithful, knew only survival.\n"
        "Civilians wept in the streets; soldiers drank to forget.\n"
        "Some spoke bitterly of Eledhel and its rising banners.\n"
        "Others said it was not for us to judge, only to endure.\n"
        "I have written this so the memory is not lost.\n"
        "We were witness, not hero, and the world remembers little.\n");

    addChapter("Reflections on Loss",
        "Years have passed, yet still I dream of our old lands.\n"
        "The towers of Dor-Temnost are dust, but still they rise in memory.\n"
        "We recall both cruelty and loyalty, often mingled.\n"
        "The young kings of Eledhel speak of order restored.\n"
        "We remember the dead, silent among the conquered hills.\n"
        "It is not pride we carry, but understanding of cost.\n"
        "History favors victors; memory favors those who survived.\n"
        "Let this book serve as a witness to what was lost,\n"
        "and as a record that Dor-Temnost once was whole.\n"
        "Though fallen, it shaped us, and its shadow remains.\n");

    addChapter("Warnings for the Future",
        "Those who read may see lessons in ruin and exile.\n"
        "Do not mistake power alone for wisdom.\n"
        "Do not let pride blind what is true in counsel.\n"
        "Let those who rise remember the fallen.\n"
        "Eledhel may prosper, yet its growth stands upon our ashes.\n"
        "The stories of the small, the frightened, and the loyal\n"
        "must not be forgotten, or future kings will repeat folly.\n"
        "Thus, I write with trembling hand and steady mind.\n"
        "May memory endure longer than banners or crowns.\n"
        "And may those who come after learn to temper ambition.\n");
}
