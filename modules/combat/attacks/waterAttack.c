inherit "/lib/modules/combat/attacks/baseAttack.c";

public void init()
{
    ::init();
    setDamageType("water");
    addHitDictionary(({
        "spray", "lash", "shoot", "splash", "drench" }));

    addSimileDictionary(({
        "with a ferocious deluge of water", "with a blast of icy water",
        "with a roaring wave of water" }));
        
    addMissMessage("##AttackerName## ##Infinitive::resemble## a wet dishcloth. "
            "How sad.");
    
    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
            "##SimileDictionary##.", "1-50");
}



