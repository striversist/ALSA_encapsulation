/*
 * File:   alsa_control.h
 * Author: Maxime ROBIN
 *
 * Created on 17 février 201, 09:57
 */

#ifndef ALSA_CONTROL_H
#define ALSA_CONTROL_H

#include <iostream>
#include <alsa/asoundlib.h>
#include <wav_functions.h>

#define STEREO 2
#define MONO 1

using std::cout;
using std::endl;

class alsa_control {
public:

    void record_to_file(std::string filename, int duration_in_us);

    alsa_control(unsigned int rate, unsigned long frames, int bits, unsigned int stereo_mode);
    ~alsa_control();

private:
    unsigned int _rate;
    unsigned int _stereo_mode;
    int _bits;
    unsigned int _time_period;

    snd_pcm_hw_params_t *_params;
    snd_pcm_t *_handle;
    snd_pcm_uframes_t _frames;
    snd_pcm_uframes_t _period_size;

    void open_pcm_device();
    void set_parameters_ALSA();

    alsa_control() = delete;
    alsa_control(const alsa_control &) = delete;

};

#endif /* ALSA_CONTROL_H */