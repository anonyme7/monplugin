/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "AdditionComponent.h"
#include "ConstanteComponent.h"

//==============================================================================
/**
*/
class MonpluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    MonpluginAudioProcessorEditor (MonpluginAudioProcessor&);
    ~MonpluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void mouseDown(const juce::MouseEvent& event) override;
    void removeAdditionComponent(AdditionComponent* comp);
    void removeConstanteComponent(ConstanteComponent* comp);

    void selectComponent(juce::Component* component)
    {
        // Désélectionner l'ancien composant
        if (selectedComponent != nullptr)
        {
            if (auto* comp = dynamic_cast<ComponentPerso*>(selectedComponent))
                comp->setSelected(false);
        }

        // Sélectionner le nouveau composant
        selectedComponent = component;
        if (component != nullptr)
        {
            if (auto* comp = dynamic_cast<ComponentPerso*>(component))
                comp->setSelected(true);
        }
    }

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MonpluginAudioProcessor& audioProcessor;

    juce::OwnedArray<ComponentPerso> components; // Liste unifiée pour tous les composants
    juce::Component* selectedComponent = nullptr;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MonpluginAudioProcessorEditor)
};
