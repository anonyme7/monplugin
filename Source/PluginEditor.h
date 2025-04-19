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

    void childComponentClicked(juce::Component* component);

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MonpluginAudioProcessor& audioProcessor;

    juce::OwnedArray<AdditionComponent> additionComponents;
    juce::OwnedArray<ConstanteComponent> constanteComponents;

    juce::Component* selectedComponent = nullptr;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MonpluginAudioProcessorEditor)
};
