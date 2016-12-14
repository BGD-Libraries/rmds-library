#ifndef _RMDS_H_
#define _RMDS_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

class Crmds
{
  public:
    typedef enum
    {
        // NONE_MODE                      = 0x00,
        PWM_MODE                       = 0x01,
        PWM_CURRENT_MODE               = 0x02,
        PWM_VELOCITY_MODE              = 0x03,
        PWM_POSITION_MODE              = 0x04,
        PWM_VELOCITY_POSITION_MODE     = 0x05,
        CURRENT_VELOCITY_MODE          = 0x06,
        CURRENT_POSITION_MODE          = 0x07,
        CURRENT_VELOCITY_POSITION_MODE = 0x08,
    }rmds_mode_e;

    Crmds(uint32_t temp_machine_ID);
    void reset();
    void autoSend(bool flag);
    void set_mode(Crmds::rmds_mode_e temp_mode);
    void set_pwm(int16_t temp_pwm);             //-5000~5000
    void set_current(int16_t temp_current);     //mA
    void set_velocity(int16_t temp_velocity);   //RPM
    void set_position(int32_t temp_position);   //qc
    void write_data(uint32_t *temp_can_ID, uint8_t temp_tx_data[]);
    bool read_data(uint32_t *temp_can_ID, uint8_t temp_rx_data[]);
    void send_data(void);
    void register_callback(void (*callBackfun)(uint32_t *, uint8_t *));
    int16_t get_real_current();
    int16_t get_real_velocity();
    int32_t get_real_position();
    void config(uint8_t temp_time);
  private:
    const uint32_t machine_ID;
    uint32_t can_ID;
    rmds_mode_e mode;
    bool autoSendFlag;
    int16_t pwm;
    int16_t current;
    int16_t velocity;
    int32_t position;
    int16_t real_current;
    int16_t real_velocity;
    int32_t real_position;
    uint8_t return_time;
    void (*send)(uint32_t *, uint8_t *);
};
#endif //_RMDS_H_
