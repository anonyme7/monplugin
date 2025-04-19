/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "AdditionComponent.h"

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

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MonpluginAudioProcessor& audioProcessor;

    juce::OwnedArray<AdditionComponent> additionComponents;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MonpluginAudioProcessorEditor)
};
