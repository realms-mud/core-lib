//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Argloth: Descent into Zhardeg");
    set("short", "A journal about Argloth's Expedition, Vol I");
    set("title",
        "Argloth's Journals: The Shadow of Zhardeg");
    set("aliases",
        ({ "argloth journal", "journal", "book", "diary", "volume 1", "vol i",
            "a journal about argloth's expedition, vol i" 
            }));
    set("long",
        "A record of Argloth's expeditions to Zhardeg and the surrounding "
        "mountains. Each chapter is a fragment from his journal, showing "
        "how fascination with power slowly overcame prudence and duty.");

    addChapter("Approaching Zhardeg",
        "The mountains rise like jagged teeth against the sky.\n"
        "I ride with careful steps, the wind biting through my cloak.\n"
        "Each stone and shadow seems alive, testing resolve.\n"
        "The dwarves murmur prayers, clinging to old charms.\n"
        "I nod, but my mind is elsewhere, drawn to the dark tower.\n"
        "Zhardeg waits, silent and patient, a promise in stone.\n"
        "I cannot shake the sense that it watches, measures intent.\n"
        "I wonder if the Keepers' warnings were not of dragons or men,\n"
        "but of something older, something that bends the will.\n"
        "The first night, I dream of voices, low, coaxing, patient.\n"
        "I wake, and the fire is cold, yet my hands still tremble.\n"
        "I record nothing for the men; they need only courage and steel.\n"
        "But in my journal, I write every flicker, every shadow.\n"
        "Tomorrow we reach the tower, and I will step beyond fear.\n"
        "Yet fear is already inside me, whispering my own name.\n"
        "I feel it in my chest, in my pulse, in the quiet between stars.\n"
        "Perhaps the Keepers were right. Perhaps I am not ready.\n"
        "Yet the lure is too strong. I cannot turn away.\n"
        "Tonight, I will sleep as a man, tomorrow, perhaps not.\n"
        "[Marginal note: 'I sense the first stirrings of my obsession.']");

    addChapter("First Sight of the Tower",
        "Zhardeg rises beyond the ridge, black against white snow.\n"
        "The winds scream, carrying whispers that feel almost sentient.\n"
        "I see the runes etched into its walls, older than memory.\n"
        "The Keepers' warnings echo, but the thrill overwhelms caution.\n"
        "I order scouts to the flanks, though their eyes betray unease.\n"
        "Inside me, a strange clarity pulses; I feel the world shift.\n"
        "The first touch of Zhardeg's influence, subtle, irresistible.\n"
        "I find myself speaking aloud, explaining my intent to stones.\n"
        "They answer not, yet I feel a response in my thoughts.\n"
        "My dwarves are uneasy; they glance at each other and whisper.\n"
        "I dismiss their fear as weakness, though a shadow gnaws at me.\n"
        "I spend hours mapping the outer walls, noting traps and ruins.\n"
        "At night, I sit alone, tracing runes with trembling fingers.\n"
        "A hum in the stone, a pulse, a heartbeat almost mine.\n"
        "I do not sleep well; I dream of Sylthasis coiled around the peaks.\n"
        "I see its eyes, glowing, and feel its patience as an accusation.\n"
        "The tower waits, the dragon waits, and I feel my will fray.\n"
        "I begin to hunger for power, for knowledge beyond prudence.\n"
        "The men do not know; I hide the quiver in my chest.\n"
        "[Marginal note: 'I speak less to them, more to Zhardeg itself.']");

    addChapter("Into the Lower Halls",
        "We enter the lower halls, chambers of dust and shattered stone.\n"
        "The air is thick, smelling of rot and of memory.\n"
        "I light torches, but the shadows still move where they should not.\n"
        "A dwarf stumbles; I catch him. He whispers prayers I do not hear.\n"
        "I trace my hand along walls, feeling the pulse beneath runes.\n"
        "Something watches from every corner, patient, waiting.\n"
        "I wonder if the dragon sleeps in these veins of stone.\n"
        "I tell myself we are mapping only, yet my pulse quickens.\n"
        "Each door feels like a test, each corridor a challenge to courage.\n"
        "I begin to sketch the runes, copying what I cannot read.\n"
        "I feel the stone answering, shaping my intent into hunger.\n"
        "The men murmur that the halls are haunted; I tell them they lie.\n"
        "Yet in my journal, I write of whispers, of pulse, of the air thickening.\n"
        "I realize I no longer see only walls, but possibilities.\n"
        "Power waits here, just beyond the door, and I ache to grasp it.\n"
        "I lie to the men, and soon I lie to myself.\n"
        "At night, I hear the dragon roar in dreams, and feel its shadow fall.\n"
        "The line between caution and obsession is fading.\n"
        "[Marginal note: 'The Keepers feared this. I understand now.']");

    addChapter("The First Test",
        "I descend into a chamber marked with sigils of the Keepers.\n"
        "The stones hum beneath my fingers, alive with old magic.\n"
        "The men hesitate; I press forward, drawing them with my will.\n"
        "A faint whisper in the air: promise, warning, song? I cannot tell.\n"
        "I feel Sylthasis coiling through the mountain, feeling me in turn.\n"
        "I know the dragon waits above, patient, terrible.\n"
        "And I hunger to confront it, to bend its will to mine.\n"
        "I map, I touch, I record; every act feeds the whisper.\n"
        "I see in the shadows visions of conquest and ruin intertwined.\n"
        "I begin to speak aloud to stones, expecting a reply in silence.\n"
        "The dwarves are uneasy; their faith falters. I push them harder.\n"
        "I tell myself it is duty, but the tremor in my hands says otherwise.\n"
        "The air hums; the stone pulses beneath me. I am not alone.\n"
        "The dragon waits. Zhardeg waits. And I feel myself shifting.\n"
        "This is not merely exploration; this is the first step of change.\n"
        "I write all in my journal, knowing it may be read by none but me.\n"
        "The first fissure in my reason has opened.\n"
        "[Marginal note: 'I do not fear the power, I fear my restraint.']");
}
