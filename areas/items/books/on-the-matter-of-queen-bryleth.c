//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "On the Matter of Queen Bryleth");
    set("short", "A slim treatise bound in dark violet leather");
    set("title", "On the Matter of Queen Bryleth, called 'the Vain' "
        "- A Treatise by the Scions of Dhuras");
    set("aliases", ({ "treatise", "bryleth", "matter of queen bryleth",
        "treatise on bryleth", "violet book", "book" }));
    set("long", "A slim volume bound in dark violet leather that "
        "has aged to near-black. The title is stamped in silver "
        "leaf that still catches the light: 'On the Matter of Queen "
        "Bryleth.' A seal on the inner cover bears the sigil of the "
        "Scions of Dhuras.");

    addChapter("Preface",
        "This treatise has been compiled by the scholars of the "
        "Scions of Dhuras over several generations. It concerns "
        "the woman known to history as Bryleth 'the Vain', Queen "
        "of Andurath, who assumed the throne in Year 315 upon the "
        "murder of her husband Elonoch III and who was expelled "
        "from Kharand in Year 859.\n\n"
        "The span of her recorded rule - some 544 years - is the "
        "central mystery addressed herein. No mortal woman, however "
        "gifted by art or nature, could reign so long. The Scions "
        "have therefore conducted extensive research into her true "
        "identity, and what follows is the sum of our findings.\n\n"
        "We caution the reader: what is written here borders on "
        "the heretical. We present it nonetheless, for the pursuit "
        "of truth must not be shackled by the comfort of "
        "convention.");

    addChapter("The Historical Record",
        "What is known with certainty:\n\n"
        "In Year 315, Bryleth murdered Elonoch III and seized the "
        "throne of Andurath (then still styling itself Dor-Temnost). "
        "She immediately sued for peace with the alliance, "
        "relinquishing vast territorial claims. This was, at the "
        "time, seen as pragmatic - the empire was overextended and "
        "her husband's war was failing.\n\n"
        "Over the following centuries, Bryleth maintained Andurath "
        "as a stable if isolationist power. She waged war on "
        "Kharand (Year 327), made peace (Year 398), and largely "
        "kept her borders quiet. She was known for her beauty, "
        "which did not diminish with the passage of years, and for "
        "a cold, calculating intelligence.\n\n"
        "In Year 859, she was expelled from Kharand. The "
        "circumstances of this expulsion are poorly documented - "
        "the Kharandish records from this period were largely "
        "destroyed. Bryleth vanished from the historical record "
        "entirely after this date.\n\n"
        "She was never seen to age.");

    addChapter("The Theological Connection",
        "The Scions' archives contain a fragmentary account from a "
        "Keeper of the Night acolyte, captured during Argloth's "
        "assault on Zhardeg in Year 1691. Under duress, the acolyte "
        "revealed that the Keepers worship a being they call 'the "
        "Queen' or 'Her Dark Majesty' - a goddess of destruction "
        "whom they believe was imprisoned long ago by the Valar.\n\n"
        "The acolyte named this goddess: Seilyndria.\n\n"
        "Cross-referencing with the oldest texts in our library, "
        "we find scattered references to a being of that name in "
        "pre-Numenorean sources. She is described as a goddess of "
        "terrible beauty and great power who fell to darkness in "
        "the earliest ages of the world. Her domains were "
        "destruction, ruin, and the unmaking of what others had "
        "built.\n\n"
        "The texts agree on one detail: her imprisonment. She was "
        "bound and sealed away, though the location varies by "
        "source. Some say a mountain. Some say beneath a great "
        "fortress. One fragmentary verse, recovered from the "
        "catacombs beneath this very keep, reads:\n\n"
        "  'Where the vain queen fell,\n"
        "   There the dark one dwells,\n"
        "   Bound in stone and sealed in blood,\n"
        "   Waiting for the obedient flood.'");

    addChapter("The Hypothesis",
        "We propose the following: that Queen Bryleth 'the Vain' "
        "of Andurath was, in truth, the goddess Seilyndria "
        "operating under mortal guise.\n\n"
        "The evidence is circumstantial but compelling:\n\n"
        "First, the impossible lifespan. 544 years of unaging "
        "rule cannot be explained by any known art of men.\n\n"
        "Second, the epithet 'the Vain'. In ancient Adunaic, the "
        "word translated as 'vain' carries a secondary meaning: "
        "'beautiful beyond mortal measure.' This is consistently "
        "how Seilyndria is described in the fragmentary texts.\n\n"
        "Third, the Keepers of the Night emerged shortly after "
        "Bryleth's disappearance from Kharand. Their worship of "
        "a 'Queen' who is also a goddess of destruction aligns "
        "precisely with what Bryleth was - or appeared to be.\n\n"
        "Fourth, the site upon which this keep was built. Local "
        "tradition holds that this was the place where 'a great "
        "queen was defeated and bound.' If Seilyndria was "
        "imprisoned here, and Bryleth was Seilyndria, then the "
        "Keepers' interest in this ruin becomes clear: they seek "
        "to free their goddess.");

    addChapter("The Sealed Door",
        "Deep within the temple section of this keep lies a door "
        "that has resisted all attempts at opening. It is carved "
        "from a single slab of amethyst - a stone associated in "
        "our oldest texts with binding magic.\n\n"
        "The door bears no lock, no handle, no visible mechanism. "
        "Argloth himself attempted to open it and failed. The "
        "wards upon it are of an order of magnitude beyond anything "
        "our scholars have encountered.\n\n"
        "If our hypothesis is correct, what lies beyond that door "
        "is not treasure, nor knowledge, nor any material prize. "
        "It is a prison.\n\n"
        "We urge any who read this: do not attempt to open it. "
        "Whatever promises are made, whatever tests are offered, "
        "whatever noble purpose seems to justify the act - the "
        "thing beyond that door must remain sealed.\n\n"
        "Some doors are closed for a reason.\n\n"
        "[The final line is underscored three times.]");
}
