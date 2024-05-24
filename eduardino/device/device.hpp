#pragma once
#include <eduardino_int_types.hpp>
#include <avr/io.h>

const bitFlag_t adts0 = mBv(0);
const bitFlag_t adts1 = mBv(1);
const bitFlag_t adts2 = mBv(2);
const bitFlag_t ipr = mBv(5);
const bitFlag_t acme = mBv(6);
const bitFlag_t bin = mBv(7);

struct adcsrb_fields : public FSRmixin<adcsrb_fields> {
	unsigned adts :3;
	unsigned :2;
	unsigned ipr :1;
	unsigned acme :1;
	unsigned bin :1;
}static volatile & ADCSRBfields = (adcsrb_fields&) ADCSRB;

const bitFlag_t adps0 = mBv(0);
const bitFlag_t adps1 = mBv(1);
const bitFlag_t adps2 = mBv(2);
const bitFlag_t adie = mBv(3);
const bitFlag_t adif = mBv(4);
const bitFlag_t adate = mBv(5);
const bitFlag_t adsc = mBv(6);
const bitFlag_t aden = mBv(7);

struct adcsra_fields : public FSRmixin<adcsra_fields> {
	unsigned adps :3;
	unsigned adie :1;
	unsigned adif :1;
	unsigned adate :1;
	unsigned adsc :1;
	unsigned aden :1;
}static volatile & ADCSRAfields = (adcsra_fields&) ADCSRA;

const bitFlag_t mux0 = mBv(0);
const bitFlag_t mux1 = mBv(1);
const bitFlag_t mux2 = mBv(2);
const bitFlag_t mux3 = mBv(3);
const bitFlag_t refs2 = mBv(4);
const bitFlag_t adlar = mBv(5);
const bitFlag_t refs0 = mBv(6);
const bitFlag_t refs1 = mBv(7);

struct admux_fields : public FSRmixin<admux_fields> {
	unsigned mux :4;
	unsigned refs2 :1;
	unsigned adlar :1;
	unsigned refs :2;
}static volatile & ADMUXfields = (admux_fields&) ADMUX;

const bitFlag_t acis0 = mBv(0);
const bitFlag_t acis1 = mBv(1);
const bitFlag_t acie = mBv(3);
const bitFlag_t aci = mBv(4);
const bitFlag_t aco = mBv(5);
const bitFlag_t acbg = mBv(6);
const bitFlag_t acd = mBv(7);

struct acsr_fields : public FSRmixin<acsr_fields> {
	unsigned acis :2;
	unsigned :1;
	unsigned acie :1;
	unsigned aci :1;
	unsigned aco :1;
	unsigned acbg :1;
	unsigned acd :1;}static volatile & ACSRfields = (acsr_fields&) ACSR;

const bitFlag_t usitc = mBv(0);
const bitFlag_t usiclk = mBv(1);
const bitFlag_t usics0 = mBv(2);
const bitFlag_t usics1 = mBv(3);
const bitFlag_t usiwm0 = mBv(4);
const bitFlag_t usiwm1 = mBv(5);
const bitFlag_t usioie = mBv(6);
const bitFlag_t usisie = mBv(7);

struct usicr_fields : public FSRmixin<usicr_fields> {
	unsigned usitc :1;
	unsigned usiclk :1;
	unsigned usics :2;
	unsigned usiwm :2;
	unsigned usioie :1;
	unsigned usisie :1;
}static volatile & USICRfields = (usicr_fields&) USICR;

const bitFlag_t usicnt0 = mBv(0);
const bitFlag_t usicnt1 = mBv(1);
const bitFlag_t usicnt2 = mBv(2);
const bitFlag_t usicnt3 = mBv(3);
const bitFlag_t usidc = mBv(4);
const bitFlag_t usipf = mBv(5);
const bitFlag_t usioif = mBv(6);
const bitFlag_t usisif = mBv(7);

struct usisr_fields : public FSRmixin<usisr_fields> {
	unsigned usicnt :4;
	unsigned usidc :1;
	unsigned usipf :1;
	unsigned usioif :1;
	unsigned usisif :1;
}static volatile & USISRfields = (usisr_fields&) USISR;

const bitFlag_t ain0d = mBv(0);
const bitFlag_t ain1d = mBv(1);
const bitFlag_t adc1d = mBv(2);
const bitFlag_t adc3d = mBv(3);
const bitFlag_t adc2d = mBv(4);
const bitFlag_t adc0d = mBv(5);

struct didr0_fields : public FSRmixin<didr0_fields> {
	unsigned ain0d :1;
	unsigned ain1d :1;
	unsigned adc1d :1;
	unsigned adc3d :1;
	unsigned adc2d :1;
	unsigned adc0d :1;
}static volatile & DIDR0fields = (didr0_fields&) DIDR0;

const bitFlag_t pcint0 = mBv(0);
const bitFlag_t pcint1 = mBv(1);
const bitFlag_t pcint2 = mBv(2);
const bitFlag_t pcint3 = mBv(3);
const bitFlag_t pcint4 = mBv(4);
const bitFlag_t pcint5 = mBv(5);

struct pcmsk_fields : public FSRmixin<pcmsk_fields> {
	unsigned pcint :6;
}static volatile & PCMSKfields = (pcmsk_fields&) PCMSK;

const bitFlag_t pinb0 = mBv(0);
const bitFlag_t pinb1 = mBv(1);
const bitFlag_t pinb2 = mBv(2);
const bitFlag_t pinb3 = mBv(3);
const bitFlag_t pinb4 = mBv(4);
const bitFlag_t pinb5 = mBv(5);

struct pinb_fields : public FSRmixin<pinb_fields> {
	unsigned pinb :6;
}static volatile & PINBfields = (pinb_fields&) PINB;

const bitFlag_t ddb0 = mBv(0);
const bitFlag_t ddb1 = mBv(1);
const bitFlag_t ddb2 = mBv(2);
const bitFlag_t ddb3 = mBv(3);
const bitFlag_t ddb4 = mBv(4);
const bitFlag_t ddb5 = mBv(5);

struct ddrb_fields : public FSRmixin<ddrb_fields> {
	unsigned ddb :6;
}static volatile & DDRBfields = (ddrb_fields&) DDRB;

const bitFlag_t pb0 = mBv(0);
const bitFlag_t pb1 = mBv(1);
const bitFlag_t pb2 = mBv(2);
const bitFlag_t pb3 = mBv(3);
const bitFlag_t pb4 = mBv(4);
const bitFlag_t pb5 = mBv(5);

struct portb_fields : public FSRmixin<portb_fields> {
	unsigned pb :6;
}static volatile & PORTBfields = (portb_fields&) PORTB;

const bitFlag_t eere = mBv(0);
const bitFlag_t eepe = mBv(1);
const bitFlag_t eempe = mBv(2);
const bitFlag_t eerie = mBv(3);
const bitFlag_t eepm0 = mBv(4);
const bitFlag_t eepm1 = mBv(5);

struct eecr_fields : public FSRmixin<eecr_fields> {
	unsigned eere :1;
	unsigned eepe :1;
	unsigned eempe :1;
	unsigned eerie :1;
	unsigned eepm :2;
}static volatile & EECRfields = (eecr_fields&) EECR;

const bitFlag_t pradc = mBv(0);
const bitFlag_t prusi = mBv(1);
const bitFlag_t prtim0 = mBv(2);
const bitFlag_t prtim1 = mBv(3);

struct prr_fields : public FSRmixin<prr_fields> {
	unsigned pradc :1;
	unsigned prusi :1;
	unsigned prtim :2;
}static volatile & PRRfields = (prr_fields&) PRR;

const bitFlag_t wdp0 = mBv(0);
const bitFlag_t wdp1 = mBv(1);
const bitFlag_t wdp2 = mBv(2);
const bitFlag_t wde = mBv(3);
const bitFlag_t wdce = mBv(4);
const bitFlag_t wdp3 = mBv(5);
const bitFlag_t wdie = mBv(6);
const bitFlag_t wdif = mBv(7);

struct wdtcr_fields : public FSRmixin<wdtcr_fields> {
	unsigned wdp :3;
	unsigned wde :1;
	unsigned wdce :1;
	unsigned wdp3 :1;
	unsigned wdie :1;
	unsigned wdif :1;
}static volatile & WDTCRfields = (wdtcr_fields&) WDTCR;

const bitFlag_t dtps10 = mBv(0);
const bitFlag_t dtps11 = mBv(1);

struct dtps1_fields : public FSRmixin<dtps1_fields> {
	unsigned dtps1 :2;
}static volatile & DTPS1fields = (dtps1_fields&) DTPS1;

const bitFlag_t dt1bl0 = mBv(0);
const bitFlag_t dt1bl1 = mBv(1);
const bitFlag_t dt1bl2 = mBv(2);
const bitFlag_t dt1bl3 = mBv(3);
const bitFlag_t dt1bh0 = mBv(4);
const bitFlag_t dt1bh1 = mBv(5);
const bitFlag_t dt1bh2 = mBv(6);
const bitFlag_t dt1bh3 = mBv(7);

struct dt1b_fields : public FSRmixin<dt1b_fields> {
	unsigned dt1bl :4;
	unsigned dt1bh :4;
}static volatile & DT1Bfields = (dt1b_fields&) DT1B;

const bitFlag_t dt1al0 = mBv(0);
const bitFlag_t dt1al1 = mBv(1);
const bitFlag_t dt1al2 = mBv(2);
const bitFlag_t dt1al3 = mBv(3);
const bitFlag_t dt1ah0 = mBv(4);
const bitFlag_t dt1ah1 = mBv(5);
const bitFlag_t dt1ah2 = mBv(6);
const bitFlag_t dt1ah3 = mBv(7);

struct dt1a_fields : public FSRmixin<dt1a_fields> {
	unsigned dt1al :4;
	unsigned dt1ah :4;
}static volatile & DT1Afields = (dt1a_fields&) DT1A;

const bitFlag_t clkps0 = mBv(0);
const bitFlag_t clkps1 = mBv(1);
const bitFlag_t clkps2 = mBv(2);
const bitFlag_t clkps3 = mBv(3);
const bitFlag_t clkpce = mBv(7);

struct clkpr_fields : public FSRmixin<clkpr_fields> {
	unsigned clkps :4;
	unsigned :3;
	unsigned clkpce :1;
}static volatile & CLKPRfields = (clkpr_fields&) CLKPR;

const bitFlag_t plock = mBv(0);
const bitFlag_t plle = mBv(1);
const bitFlag_t pcke = mBv(2);
const bitFlag_t lsm = mBv(7);

struct pllcsr_fields : public FSRmixin<pllcsr_fields> {
	unsigned plock :1;
	unsigned plle :1;
	unsigned pcke :1;
	unsigned :4;
	unsigned lsm :1;
}static volatile & PLLCSRfields = (pllcsr_fields&) PLLCSR;

const bitFlag_t wgm00 = mBv(0);
const bitFlag_t wgm01 = mBv(1);
const bitFlag_t com0b0 = mBv(4);
const bitFlag_t com0b1 = mBv(5);
const bitFlag_t com0a0 = mBv(6);
const bitFlag_t com0a1 = mBv(7);

struct tccr0a_fields : public FSRmixin<tccr0a_fields> {
	unsigned wgm0 :2;
	unsigned :2;
	unsigned com0b :2;
	unsigned com0a :2;
}static volatile & TCCR0Afields = (tccr0a_fields&) TCCR0A;

const bitFlag_t psr0 = mBv(0);
const bitFlag_t psr1 = mBv(1);
const bitFlag_t foc1a = mBv(2);
const bitFlag_t foc1b = mBv(3);
const bitFlag_t com1b0 = mBv(4);
const bitFlag_t com1b1 = mBv(5);
const bitFlag_t pwm1b = mBv(6);
const bitFlag_t tsm = mBv(7);

struct gtccr_fields : public FSRmixin<gtccr_fields> {
	unsigned psr :2;
	unsigned foc1a :1;
	unsigned foc1b :1;
	unsigned com1b :2;
	unsigned pwm1b :1;
	unsigned tsm :1;
}static volatile & GTCCRfields = (gtccr_fields&) GTCCR;

const bitFlag_t cs10 = mBv(0);
const bitFlag_t cs11 = mBv(1);
const bitFlag_t cs12 = mBv(2);
const bitFlag_t cs13 = mBv(3);
const bitFlag_t com1a0 = mBv(4);
const bitFlag_t com1a1 = mBv(5);
const bitFlag_t pwm1a = mBv(6);
const bitFlag_t ctc1 = mBv(7);

struct tccr1_fields : public FSRmixin<tccr1_fields> {
	unsigned cs1 :4;
	unsigned com1a :2;
	unsigned pwm1a :1;
	unsigned ctc1 :1;
}static volatile & TCCR1fields = (tccr1_fields&) TCCR1;

const bitFlag_t cs00 = mBv(0);
const bitFlag_t cs01 = mBv(1);
const bitFlag_t cs02 = mBv(2);
const bitFlag_t wgm02 = mBv(3);
const bitFlag_t foc0b = mBv(6);
const bitFlag_t foc0a = mBv(7);

struct tccr0b_fields : public FSRmixin<tccr0b_fields> {
	unsigned cs0 :3;
	unsigned wgm02 :1;
	unsigned :2;
	unsigned foc0b :1;
	unsigned foc0a :1;
}static volatile & TCCR0Bfields = (tccr0b_fields&) TCCR0B;

const bitFlag_t porf = mBv(0);
const bitFlag_t extrf = mBv(1);
const bitFlag_t borf = mBv(2);
const bitFlag_t wdrf = mBv(3);

struct mcusr_fields : public FSRmixin<mcusr_fields> {
	unsigned porf :1;
	unsigned extrf :1;
	unsigned borf :1;
	unsigned wdrf :1;
}static volatile & MCUSRfields = (mcusr_fields&) MCUSR;

const bitFlag_t isc00 = mBv(0);
const bitFlag_t isc01 = mBv(1);
const bitFlag_t bodse = mBv(2);
const bitFlag_t sm0 = mBv(3);
const bitFlag_t sm1 = mBv(4);
const bitFlag_t se = mBv(5);
const bitFlag_t pud = mBv(6);
const bitFlag_t bods = mBv(7);

struct mcucr_fields : public FSRmixin<mcucr_fields> {
	unsigned isc0 :2;
	unsigned bodse :1;
	unsigned sm :2;
	unsigned se :1;
	unsigned pud :1;
	unsigned bods :1;
}static volatile & MCUCRfields = (mcucr_fields&) MCUCR;

const bitFlag_t spmen = mBv(0);
const bitFlag_t pgers = mBv(1);
const bitFlag_t pgwrt = mBv(2);
const bitFlag_t rflb = mBv(3);
const bitFlag_t ctpb = mBv(4);
const bitFlag_t rsig = mBv(5);

struct spmcsr_fields : public FSRmixin<spmcsr_fields> {
	unsigned spmen :1;
	unsigned pgers :1;
	unsigned pgwrt :1;
	unsigned rflb :1;
	unsigned ctpb :1;
	unsigned rsig :1;
}static volatile & SPMCSRfields = (spmcsr_fields&) SPMCSR;

const bitFlag_t tov0 = mBv(1);
const bitFlag_t tov1 = mBv(2);
const bitFlag_t ocf0b = mBv(3);
const bitFlag_t ocf0a = mBv(4);
const bitFlag_t ocf1b = mBv(5);
const bitFlag_t ocf1a = mBv(6);

struct tifr_fields : public FSRmixin<tifr_fields> {
	unsigned :1;
	unsigned tov :2;
	unsigned ocf0b :1;
	unsigned ocf0a :1;
	unsigned ocf1b :1;
	unsigned ocf1a :1;
}static volatile & TIFRfields = (tifr_fields&) TIFR;

const bitFlag_t toie0 = mBv(1);
const bitFlag_t toie1 = mBv(2);
const bitFlag_t ocie0b = mBv(3);
const bitFlag_t ocie0a = mBv(4);
const bitFlag_t ocie1b = mBv(5);
const bitFlag_t ocie1a = mBv(6);

struct timsk_fields : public FSRmixin<timsk_fields> {
	unsigned :1;
	unsigned toie :2;
	unsigned ocie0b :1;
	unsigned ocie0a :1;
	unsigned ocie1b :1;
	unsigned ocie1a :1;
}static volatile & TIMSKfields = (timsk_fields&) TIMSK;

const bitFlag_t pcif = mBv(5);
const bitFlag_t intf0 = mBv(6);

struct gifr_fields : public FSRmixin<gifr_fields> {
	unsigned :5;
	unsigned pcif :1;
	unsigned intf0 :1;
}static volatile & GIFRfields = (gifr_fields&) GIFR;


