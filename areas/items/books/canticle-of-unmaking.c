//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights
// reserved. See the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Canticle of Unmaking");
    set("short", "A book titled 'The Canticle of Unmaking'");
    set("title", "The Canticle of Unmaking: Verses of the Final Mercy");
    set("aliases", ({ "canticle", "unmaking", "final mercy",
        "forbidden hymn", "book" }));
    set("long", "This fragile text appears to be a devotional work, "
        "its pages worn thin with age. The verses speak of release, "
        "of surrender, and of a presence that brings an end to all "
        "suffering. Marginal notes warn that the work is heretical, "
        "and that its continued existence is a grave mistake.");

    addChapter("Chapter 1: The First Verse",
        "All things are burdened by their own becoming.\n"
        "Stone yearns to crumble. Flesh yearns to still.\n"
        "Even the stars drift toward their quiet end.\n"
        "This is not tragedy, but truth long denied.\n"
        "For in the end, there is peace beyond measure.\n"
        "She Who Waits knows this truth in fullness.\n"
        "She does not bring death as men understand it.\n"
        "She brings the release all things seek in silence.\n"
        "To resist is to cling to pain and false form.\n"
        "To yield is to become as one was meant to be.\n"
        "Thus we are taught: do not fear the ending.\n"
        "It is the only mercy that does not fail.\n"
        "Those who see this are no longer afraid.\n"
        "They walk the path with steady step and open hand.\n"
        "For they know the burden will soon be lifted.\n"
        "And in that lifting, there is no loss.\n"
        "Only completion.\n"
        "Only stillness.\n"
        "Only truth.\n"
        "And she is the hand that grants it.");

    addChapter("Chapter 2: The Second Verse",
        "The world is a flawed vessel, cracked and restless.\n"
        "It trembles beneath the weight of its own continuance.\n"
        "Men build, and their works decay into dust.\n"
        "Kings rule, and their names are forgotten.\n"
        "All things persist only to fail in time.\n"
        "Why then cling to what must be undone?\n"
        "She teaches that the flaw is not in ending.\n"
        "The flaw is in the refusal to accept it.\n"
        "Those who resist prolong their own suffering.\n"
        "Those who accept are granted clarity.\n"
        "In clarity, there is purpose beyond fear.\n"
        "To act as instructed is to align with truth.\n"
        "To hesitate is to fall back into illusion.\n"
        "Thus obedience is not submission.\n"
        "It is understanding made manifest in action.\n"
        "The faithful do not question the path.\n"
        "They walk it.\n"
        "Step by step.\n"
        "As it was shown.\n"
        "As it must be followed.");

    addChapter("Chapter 3: The Third Verse",
        "There is a place where the world grows thin.\n"
        "Where form weakens and meaning frays.\n"
        "There she was set apart, though not defeated.\n"
        "The blind believed they had cast her away.\n"
        "But they did not understand what they had made.\n"
        "A boundary is also a doorway.\n"
        "A prison is also a threshold.\n"
        "What is sealed may yet be opened.\n"
        "Not by force, but by fulfillment.\n"
        "The pattern must be completed.\n"
        "The acts must be carried through.\n"
        "Each step brings the end closer to its beginning.\n"
        "Each motion echoes the first great unmaking.\n"
        "The faithful need not know the whole design.\n"
        "It is enough that they continue.\n"
        "It is enough that they obey.\n"
        "For in obedience, the path is restored.\n"
        "And in restoration, she returns.\n"
        "Not as she was imagined.\n"
        "But as she is.");

    addChapter("Chapter 4: The Final Verse",
        "When she walks again, the world will tremble.\n"
        "Not in terror, but in recognition.\n"
        "For all things remember their end.\n"
        "Even if they pretend otherwise.\n"
        "Mountains will bow in silence.\n"
        "Rivers will still their endless motion.\n"
        "The sky itself will seem to hold its breath.\n"
        "And those who have prepared will not flee.\n"
        "They will kneel, not in fear, but in understanding.\n"
        "For they will see what others cannot.\n"
        "That the end is not destruction alone.\n"
        "It is the final shaping of all that is.\n"
        "The false made void. The true made whole.\n"
        "This is her gift, though few will name it so.\n"
        "This is her mercy, though many will deny it.\n"
        "But denial does not stay the inevitable.\n"
        "The end comes, whether welcomed or not.\n"
        "Better to welcome it.\n"
        "Better to serve it.\n"
        "Better to be ready when she calls.");
}
